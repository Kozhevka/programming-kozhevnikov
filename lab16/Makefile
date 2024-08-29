CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: lab16

lab16: src/main.c src/list.c src/entity.c src/menu.c
	$(CC) $(CFLAGS) -o lab16 src/main.c src/list.c src/entity.c src/menu.c

test: test/test.c src/list.c src/entity.c
	$(CC) $(CFLAGS) -o test/test test/test.c src/list.c src/entity.c

clean:
	rm -f lab16 test/test
