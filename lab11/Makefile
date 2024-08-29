CC=gcc
CFLAGS=-Wall -Wextra -g
TARGET=main
TEST_PROG=test_prog
LIB_SRC=src/lib.c
TEST_SRC=src/main.c
MAIN_SRC=src/main.c
LIB_OBJ=$(LIB_SRC:.c=.o)
TEST_OBJ=$(TEST_SRC:.c=.o)
MAIN_OBJ=$(MAIN_SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(MAIN_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TEST_PROG)
	./$(TEST_PROG)

$(TEST_PROG): $(TEST_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(TARGET)
	valgrind ./$(TARGET)

run: $(TARGET)
	gdb ./$(TARGET)

clean:
	rm -f $(TARGET) $(LIB_OBJ) $(TEST_OBJ) $(MAIN_OBJ) $(TEST_PROG)
