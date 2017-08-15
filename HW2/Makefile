# Sample Makefile for HW2
#
# USAGE:
#
# // to compile:
# make
#
# // to compile tests and run tests:
# make test
#
# // remove compilation output files:
# make clean
#

# make variables let us avoid pasting these options in multiple places
CC = gcc 
# CFLAGS = -std=c99 -Wall -Wextra -pedantic -O         # for final build
CFLAGS = -std=c99 -Wall -Wextra -pedantic -O0 -g   # for debugging

bin: hw2

test: test_wordsearch
	@echo "Running tests..."
	./test_wordsearch
	@echo "All Tests Passed."

wordsearch.o: wordsearch.c wordsearch.h
	$(CC) $(CFLAGS) -c wordsearch.c
# (short for) gcc -std=c99 -Wall -Wextra -pedantic -O -c wordsearch.c

test_wordsearch.o: test_wordsearch.c wordsearch.h
	$(CC) $(CFLAGS) -c test_wordsearch.c

hw2.o: hw2.c wordsearch.h
	$(CC) $(CFLAGS) -pedantic -O -c hw2.c

test_wordsearch: test_wordsearch.o wordsearch.o
	$(CC) $(CFLAGS) -O -o test_wordsearch test_wordsearch.o wordsearch.o

hw2: hw2.o wordsearch.o
	$(CC) $(CFLAGS) -O -o hw2 hw2.o wordsearch.o

clean:
	rm -f *.o test_wordsearch hw2
