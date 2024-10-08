TARGET = teste 
INPUTFILE = testes/testeIF.txt
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

LIBS = -lfl

CC = gcc

all: $(TARGET)

$(YACC_OUT): $(YACC_SRC)
	bison -d $(YACC_SRC)

$(LEX_OUT): $(LEX_SRC)
	flex $(LEX_SRC)

$(SYM_OBJ): $(SYM_SRC)
	$(CC) -c $(SYM_SRC) -o $(SYM_OBJ)

$(FUNC_OBJ): $(FUNC_SRC)
	$(CC) -c $(FUNC_SRC) -o $(FUNC_OBJ)

$(TYPE_OBJ): $(TYPE_SRC)
	$(CC) -c $(TYPE_SRC) -o $(TYPE_OBJ)

$(TARGET): $(YACC_OUT) $(LEX_OUT) $(SYM_OBJ) $(FUNC_OBJ) $(TYPE_OBJ)
	$(CC) -o $(TARGET) $(YACC_OUT) $(LEX_OUT) $(SYM_OBJ) $(FUNC_OBJ) $(TYPE_OBJ) $(LIBS)

run: all
	./$(TARGET) < $(INPUTFILE)

clean:
	rm -f $(TARGET) $(YACC_OUT) yacc.tab.h $(LEX_OUT) $(SYM_OBJ) $(FUNC_OBJ) $(TYPE_OBJ)