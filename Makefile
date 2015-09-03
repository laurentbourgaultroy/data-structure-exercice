CFLAGS=-Wall -g -O0
CC=cc
BINDIR=bin
TESTBIN=$(BINDIR)/test
SOURCES=vector.c

.PHONY: all test clean

all: test
	mkdir -p bin
	$(CC) $(CFLAGS) -o $(BINDIR)/vector main.c $(SOURCES)

test: bin
	$(CC) $(CFLAGS) -o $(TESTBIN) test.c $(SOURCES)
	$(TESTBIN)
	echo "Running leak test..."
	valgrind --quiet --leak-check=yes --error-exitcode=1 $(TESTBIN)

bin:
	mkdir -p bin

clean:
	rm -rf bin