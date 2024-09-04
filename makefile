TARGET = teste 
INPUTFILE = testes/testeSoma.txt
YACC_SRC = translate.y
LEX_SRC = lex.l
YACC_OUT = translate.tab.c
LEX_OUT = lex.yy.c
SYM_SRC = structures/SymbolTable.c
SYM_OBJ = SymbolTable.o
FUNC_SRC = structures/Function.c
FUNC_OBJ = Function.o
TYPE_SRC = structures/Types.c
TYPE_OBJ = Types.o
AST_SRC = structures/AST/AST.c
AST_OBJ = AST.o
CODE_GEN = structures/LLVM/codeGen.cpp
CODE_GEN_OBJ = codeGen.o
LLVMAST = structures/LLVM/LLVMAST.cpp
LLVMAST_OBJ = LLVMAST.o

LIBS = -lfl `llvm-config --libs --system-libs --cflags --ldflags`

CC = gcc
CXX = g++
CFLAGS = -Wall -g
CXXFLAGS = -Wall -g

all: $(TARGET)

$(YACC_OUT): $(YACC_SRC)
	bison -d $(YACC_SRC)

$(LEX_OUT): $(LEX_SRC)
	flex $(LEX_SRC)

$(SYM_OBJ): $(SYM_SRC)
	$(CC) $(CFLAGS) -c $(SYM_SRC) -o $(SYM_OBJ)

$(FUNC_OBJ): $(FUNC_SRC)
	$(CC) $(CFLAGS) -c $(FUNC_SRC) -o $(FUNC_OBJ)

$(TYPE_OBJ): $(TYPE_SRC)
	$(CC) $(CFLAGS) -c $(TYPE_SRC) -o $(TYPE_OBJ)

$(AST_OBJ): $(AST_SRC)
	$(CC) $(CFLAGS) -c $(AST_SRC) -o $(AST_OBJ)

$(CODE_GEN_OBJ): $(CODE_GEN)
	$(CXX) $(CXXFLAGS) -c $(CODE_GEN) -o $(CODE_GEN_OBJ) `llvm-config --cxxflags`

$(LLVMAST_OBJ): $(LLVMAST)
	$(CXX) $(CXXFLAGS) -c $(LLVMAST) -o $(LLVMAST_OBJ) `llvm-config --cxxflags`

$(TARGET): $(YACC_OUT) $(LEX_OUT) $(SYM_OBJ) $(FUNC_OBJ) $(TYPE_OBJ) $(AST_OBJ) $(CODE_GEN_OBJ) $(LLVMAST_OBJ)
	$(CXX) -o $(TARGET) $(YACC_OUT) $(LEX_OUT) $(SYM_OBJ) $(FUNC_OBJ) $(TYPE_OBJ) $(AST_OBJ) $(CODE_GEN_OBJ) $(LLVMAST_OBJ) $(LIBS)

run: all
	./$(TARGET) < $(INPUTFILE)

clean:
	rm -f $(TARGET) $(YACC_OUT) yacc.tab.h $(LEX_OUT) $(SYM_OBJ) $(FUNC_OBJ) $(TYPE_OBJ) $(AST_OBJ) $(CODE_GEN_OBJ) $(LLVMAST_OBJ)
