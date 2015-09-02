CFLAGS=-Wall
CC=cc
BINDIR=bin
SOURCES=vector.c

.PHONY: all test clean

all: test
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(BINDIR)/vector main.c $(SOURCES)

test:
	$(CC) $(CFLAGS) -o $(BINDIR)/test test.c $(SOURCES)
	$(BINDIR)/test

clean:
	rm -f vector