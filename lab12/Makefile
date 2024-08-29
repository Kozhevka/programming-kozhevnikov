CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99

SRC_DIR = src
BUILD_DIR = out
BIN_DIR = out

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BIN_DIR)/main
TEST_TARGET = $(BIN_DIR)/test
TESTING_TARGET = $(BIN_DIR)/testing

.PHONY: all clean test testing

all: $(TARGET)

test: $(TEST_TARGET)
	@echo "Running tests..."
	@cat ./assets/input.txt | ./$(TEST_TARGET)

testing: $(TESTING_TARGET)
	@echo "Running testing..."
	@./$(TESTING_TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_TARGET): $(OBJS) test/test.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -DTEST_MODE

$(TESTING_TARGET): $(OBJS) test/test.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)