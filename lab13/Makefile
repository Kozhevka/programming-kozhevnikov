CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
SRC = src/main.c src/lib.c
TEST_SRC = test/test.c src/lib.c
OBJ = $(SRC:.c=.o)
TEST_OBJ = $(TEST_SRC:.c=.o)
BIN = bin/main
TEST_BIN = bin/test

all: $(BIN)

$(BIN): $(OBJ)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_BIN)
	./$(TEST_BIN)

$(TEST_BIN): $(TEST_OBJ)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $^

src/main.o: src/main.c src/lib.h
src/lib.o: src/lib.c src/lib.h
test/test.o: test/test.c src/lib.h

clean:
	rm -rf $(OBJ) $(BIN) $(TEST_OBJ) $(TEST_BIN)

.PHONY: all test clean
