CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/modular_arithmetic.c src/barrett_reduction.c src/montgomery_ladder.c
OBJ = $(SRC:.c=.o)
MAIN = src/main.c

all: main

main: $(OBJ) $(MAIN)
	$(CC) $(CFLAGS) -o main $(MAIN) $(OBJ)

test_modular:
	$(CC) $(CFLAGS) -o test_modular tests/test_modular.c src/modular_arithmetic.c

test_barrett:
	$(CC) $(CFLAGS) -o test_barrett tests/test_barrett.c src/barrett_reduction.c src/modular_arithmetic.c

test_montgomery:
	$(CC) $(CFLAGS) -o test_exponentiation tests/test_exponentiation.c src/exponentiation.c src/barrett_reduction.c src/modular_arithmetic.c

clean:
	rm -f main test_modular test_barrett test_exponentiation $(OBJ)
