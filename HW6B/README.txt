Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/10/2015
443-691-8192

To compile and run tests, type "make test". This will test Part A and Part B both.
To test for memory leaks, type "valgrind --leak-check=full ./fdTest" and "valgrind --leak-check=full ./ctTest"
after compiling with "make test".
If the tests run and finish successfully, it means the assignment was completed successfully.

The zip contains the following contents for Part B:
CTree.h ---- Class and function declarations.
CTree.cpp ---- Definitions and code for declarations from header file.
CTreeTest.cpp ---- Test driver that was provided to us (with added tests for both extra credit functions).

The CTree class is basically a tree class that can handle child, sibling, and parent nodes.

EXTRA CREDIT:
I implemented both the extra credit functions. Namely-
CTree(const CTree* fromTree); //Deep copy constructor
bool removeChild(char ch); //function to remove selected node