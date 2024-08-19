TARGET = teste 

YACC_SRC = yacc.y
LEX_SRC = test.l
INPUTFILE = testeIF.txt
YACC_OUT = yacc.tab.c
LEX_OUT = lex.yy.c

LIBS = -lfl

CC = gcc

all: $(TARGET)

$(YACC_OUT): $(YACC_SRC)
	bison -d $(YACC_SRC)

$(LEX_OUT): $(LEX_SRC)
	flex $(LEX_SRC)

$(TARGET): $(YACC_OUT) $(LEX_OUT)
	$(CC) -o $(TARGET) $(YACC_OUT) $(LEX_OUT) < $(INPUTFILE)

run: all
	./$(TARGET) < $(INPUTFILE)

clean:
	rm -f $(TARGET) $(YACC_OUT) yacc.tab.h $(LEX_OUT)