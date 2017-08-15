CC = g++
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -O -g
GPROF = -pg
GCOV = -fprofile-arcs -ftest-coverage

test: fdTest ctTest
	echo "Running tests..."
	./fdTest
	./ctTest

# recompiles tests with gcov on and reports the lines not tested
testgcov:
	make clean
	make CXXFLAGS="$(CXXFLAGS) $(GCOV)" test
	gcov *.cpp
	-@grep -n "#####" *.cpp.gcov

fdTest: FileDir.cpp FileDirTest.cpp
	$(CC) $(CXXFLAGS) FileDir.cpp FileDirTest.cpp -o fdTest

ctTest: CTree.cpp CTreeTest.cpp
	$(CC) $(CXXFLAGS) CTree.cpp CTreeTest.cpp -o ctTest

ttTest: FileDir.cpp Tree.cpp TreeTempTest.cpp 
	$(CC) $(CXXFLAGS) FileDir.cpp Tree.cpp TreeTest.cpp -o ttTest

clean:
	rm -f a.out *~ *.o *.gcov *.gcda *.gcno gmon.out fdTest ctTest tTest
