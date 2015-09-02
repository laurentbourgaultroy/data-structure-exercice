CFLAGS=-Wall
CC=cc

.PHONY: all clean

all:
	mkdir -p bin
	$(CC) $(CFLAGS) -o bin/vector vector.c

clean:
	rm -f vector