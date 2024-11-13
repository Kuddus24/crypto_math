CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/modular_arithmetic.c src/barrett_reduction.c src/exponentiation.c
OBJ = $(SRC:.c=.o)
MAIN = src/main.c

all: main

main: $(OBJ) $(MAIN)
	$(CC) $(CFLAGS) -o main $(MAIN) $(OBJ)

clean:
	rm -f main $(OBJ)
