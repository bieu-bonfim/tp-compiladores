TARGET = teste 
INPUTFILE = testes/testeIF.txt
YACC_SRC = yacc.y
LEX_SRC = lex.l
YACC_OUT = yacc.tab.c
LEX_OUT = lex.yy.c
SYM_SRC = structures/SymbolTable.c
SYM_OBJ = SymbolTable.o

LIBS = -lfl

CC = gcc

all: $(TARGET)

$(YACC_OUT): $(YACC_SRC)
	bison -d $(YACC_SRC)

$(LEX_OUT): $(LEX_SRC)
	flex $(LEX_SRC)

$(SYM_OBJ): $(SYM_SRC)
	$(CC) -c $(SYM_SRC) -o $(SYM_OBJ)

$(TARGET): $(YACC_OUT) $(LEX_OUT) $(SYM_OBJ)
	$(CC) -o $(TARGET) $(YACC_OUT) $(LEX_OUT) $(SYM_OBJ) $(LIBS)

run: all
	./$(TARGET) < $(INPUTFILE)

clean:
	rm -f $(TARGET) $(YACC_OUT) yacc.tab.h $(LEX_OUT) $(SYM_OBJ)