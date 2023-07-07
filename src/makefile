CXX := g++
CXXFLAGS := -std=c++17

INCLUDE := include
SRC := src
BIN := bin
EXEC := main

${BIN}/${EXEC}:
	@echo "🏛️ ️ Building ..."
	@mkdir -p ${BIN}/
	${CXX} ${CXXFLAGS} -I ${INCLUDE}/ ${SRC}/main.cpp ${SRC}/database/csv.cpp ${SRC}/dao/book.cpp -o ${BIN}/${EXEC}

run: ${BIN}/${EXEC}
	@echo "🚀 Executing ..."
	@${BIN}/main

clean:
	@echo "🧹 Cleaning ..."
	@rm -rf ${BIN}/


	RASCUNHORASCUNHORASCUNHO