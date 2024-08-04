# Nome do arquivo de entrada
INPUT_FILE = input2.txt

# Nome dos arquivos gerados
LEX_FILE = lex_color.l
LEX_OUTPUT = lex.yy.c
EXECUTABLE = a.out

# Comandos
all: $(EXECUTABLE)

$(LEX_OUTPUT): $(LEX_FILE)
	flex $(LEX_FILE)

$(EXECUTABLE): $(LEX_OUTPUT)
	gcc $(LEX_OUTPUT) -o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE) < $(INPUT_FILE)

clean:
	rm -f $(LEX_OUTPUT) $(EXECUTABLE)

.PHONY: all clean run
