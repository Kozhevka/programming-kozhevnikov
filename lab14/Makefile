CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: lab14

lab14: src/main.c src/lib.c src/lib.h
	$(CC) $(CFLAGS) -o lab14 src/main.c src/lib.c

test: src/lib.c src/lib.h test/test.c
	$(CC) $(CFLAGS) -o test/test test/test.c src/lib.c

clean:
	rm -f lab14 test/test
	rm -f cars.bin
	rm -f test_output.txt test_output.bin
