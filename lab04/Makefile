CC = clang
C_OPTS = $(MAC_OPTS) -std=gnu11 -g -Wall -Wextra -Werror -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -Wno-unused-variable -Wno-implicit-int-float-conversion -Werror=vla
SRC = scripts/main.c

all: clean prep compile check

clean:
	rm -rf build

prep:
	mkdir build

compile: main.bin

main.bin: $(SRC)
	$(CC) $(C_OPTS) $< -o ./build/$@

run: clean prep compile
	./build/main.bin

check:
	clang-format --verbose --dry-run --Werror scripts/*
	clang-tidy $(SRC) -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf scripts/*.dump
