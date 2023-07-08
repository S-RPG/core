CXX := g++
CXXFLAGS := -std=c++17

SRC := src
BIN := run
EXEC := main

${BIN}/${EXEC}:
	@mkdir -p ${BIN}/
	${CXX} ${CXXFLAGS} -I ${SRC}/main.cpp ${SRC}/decisao/decisao.hpp ${SRC}/item/item.hpp ${SRC}/loja/loja.cpp ${SRC}/situacao/situacao.cpp -o ${BIN}/${EXEC}

run: ${BIN}/${EXEC}
	@${BIN}/main

clean:
	@echo "🧹 Cleaning ..."
	@rm -rf ${BIN}/

