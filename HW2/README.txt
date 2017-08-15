Homework 2, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
2/16/2015
443-691-8192

To compile the program, unzip the files into a directory and type "make" into the command line.

To run the program, please enter the following information into the command line-

./hw2 gridfilename > outputfilename

where "gridfilename" is the name of the file that contains the grid in which to search for words, and "outputfilename" is the file where the search results will be printed.
I believe this redirection is in accordance with the assignment rules, as stated on the class website and on Piazza.

A sample "testgrid" file has been included in order to be able to test the file loading function in test_wordsearch.c. Please refer to it for a sample valid grid input.

When running the program, you must type in words to search for separated by whitespace (any amount). When finished typing words, you must press enter once and then press "control+d" once (as
per Dr. Selinski on Piazza). The program will then print the search results to the file that stdout was redirected to ("outputfilename").

For example, the sample testgrid file contains the grid-

hellot
amysda
aaeman
bbbbba
cdcdcy
asasas

Searching for "hello my name is tanay" results in the following output-

hello 0 0 R
my 1 1 R
name 2 5 L
is - Not Found
tanay 0 5 D