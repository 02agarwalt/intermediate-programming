Homework 6, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
04/14/2015
443-691-8192

To compile and test the program, type "make test" in the command line.

The zip contains all the files for HW6, including Part A, B, and C.

Part C consists of a template CTree class which can work with
any data type that has ==, <, and << defined. I aso overloaded
these operators for the FileDir class, so that it can be stored in
a CTree data structure. I also went ahead and overloaded != just
for the sake of it.

I also made a test file for testing this templated class. I simply
took the test functions given to us for Part B, and templated them.
Then I was able to simply call the functions with different data types
in main().