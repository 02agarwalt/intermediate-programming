# make variables let us avoid pasting these options in multiple places
CC = g++ 
# CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O         # for final build
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -O0 -g   # for debugging

bin: hw5

test: test_languagemodel
	@echo "Running tests..."
	./test_languagemodel < test_input.txt
	@echo "All Tests Passed."

languagemodel.o: languagemodel.cpp languagemodel.h
	$(CC) $(CXXFLAGS) -c languagemodel.cpp
# (short for) gcc -std=c++11 -Wall -Wextra -pedantic -O -c languagemodel.c

test_languagemodel.o: test_languagemodel.cpp languagemodel.h
	$(CC) $(CXXFLAGS) -c test_languagemodel.cpp

main.o: main.cpp languagemodel.h
	$(CC) $(CXXFLAGS) -pedantic -O -c main.cpp

test_languagemodel: test_languagemodel.o languagemodel.o
	$(CC) $(CXXFLAGS) -O -o test_languagemodel test_languagemodel.o languagemodel.o

hw5: main.o languagemodel.o
	$(CC) $(CXXFLAGS) -O -o hw5 main.o languagemodel.o

clean:
	rm -f *.o test_languagemodel hw5
