CC=gcc
CFLAGS=-Wall -Wextra -g
TARGET=lab10
TESTS=test_prog
LIB_SRC=src/lib.c
TEST_SRC=test/test.c  # Изменили путь к файлу с тестами
LIB_OBJ=$(LIB_SRC:.c=.o)
TEST_OBJ=$(TEST_SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(LIB_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTS): $(LIB_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

test: $(TESTS)
	./$(TESTS)

run: $(TARGET)
	gdb ./$(TARGET)

.PHONY: clean

clean:
	rm -f $(TARGET) $(LIB_OBJ) $(TEST_OBJ) $(TESTS)