# Nome do executável
TARGET = supermercado

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -g

# Arquivos fonte
SRC = main.c cliente.c caixa.c filaPrioridade.c

# Arquivos de cabeçalho
HEADERS = cliente.h caixa.h filaPrioridade.h

# Regra padrão para compilar o projeto
all: $(TARGET)

# Regra para criar o executável
$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Regra para limpar os arquivos de compilação
clean:
	rm -f $(TARGET)

# Regra para recompilar o projeto
rebuild: clean all

# Regra para compilar e executar o projeto
run: all
	./$(TARGET)
