echo "Criando 📂 build/bin/ ..."
mkdir -p build/bin/

echo "Compilando arquivos em 📄 build/bin/*.o ..."
g++ -c src/class/situacao/situacao.cpp -o build/bin/situacao.o
g++ -c src/class/inventario/inventario.cpp -o build/bin/inventario.o
g++ -c src/class/loja/loja.cpp -o build/bin/loja.o

g++ -c src/database/factory-item.cpp -o build/bin/factory-item.o
g++ -c src/database/factory-decisao.cpp -o build/bin/factory-decisao.o
g++ -c src/database/factory-situacao.cpp -o build/bin/factory-situacao.o
g++ -c src/database/factory-loja.cpp -o build/bin/factory-loja.o
g++ -c src/database/data.cpp -o build/bin/data.o

g++ -c src/main.cpp -o build/bin/main.o

echo "Construindo executavel ⚙️"
g++ build/bin/situacao.o build/bin/loja.o build/bin/inventario.o build/bin/factory-item.o build/bin/factory-decisao.o build/bin/factory-situacao.o build/bin/factory-loja.o build/bin/data.o build/bin/main.o -o war-dg

echo "Concluido 🎉"
echo "Execute o comando: ./war-dg para iniciar o jogo 🎮"
