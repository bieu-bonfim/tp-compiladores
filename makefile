TARGET = teste

SOURCES = yacc.tab.c lex.yy.c

LIBS = -lfl


CC = gcc

all: $(TARGET)


$(TARGET): $(SOURCES)
	$(CC) -o $(TARGET) $(SOURCES) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)