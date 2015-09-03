CFLAGS=-Wall -g -O0
CC=cc
BINDIR=bin
TESTBIN=$(BINDIR)/test
SOURCES=vector.c

.PHONY: all test clean

all: test
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(BINDIR)/vector main.c $(SOURCES)

test:
	$(CC) $(CFLAGS) -o $(TESTBIN) test.c $(SOURCES)
	$(TESTBIN)
	valgrind --quiet --leak-check=yes --error-exitcode=1 $(TESTBIN)

clean:
	rm -f vector