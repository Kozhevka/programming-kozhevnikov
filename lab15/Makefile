CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: lab15

lab15: src/main.c src/list.c src/entity.c
	$(CC) $(CFLAGS) -o lab15 src/main.c src/list.c src/entity.c

test: src/list.c src/entity.c test/test.c
	$(CC) $(CFLAGS) -o test/test test/test.c src/list.c src/entity.c

clean:
	rm -f lab15 test/test
