Homework 3, 600.120 Spring 2015

Tanay Agarwal and Nirmal Krishnan
tagarwa2@jhu.edu
nkrishn9@jhu.edu
tagarwa2
nkrishn9
2/27/2015
443-691-8192 - Tanay
330-840-0368 - Nirmal

Pre-Plan:

We will write functions to do the following:
-load the grid while dynamically allocating memory (by Sunday)
-generate/find every possible word in the grid (by Sunday)
-sort alphabetically (maybe use qsort) (by Sunday)
-check if search results are in alphabetized word list (by Wednesday)

To compile the program, unzip the files into a directory and type "make" into the command line.

To run the program, please enter the following information into the command line-
./hw3 gridfilename < wordlist

where "gridfilename" is the name of the file that contains the grid in which to search for words, and "wordlist" is the list
of words for which to search for.

You can also add " > outfilename" to the command line directive above. This will output the results to a file called "outfilename"
instead of printing to the screen.

A sample "testgrid.txt" file has been included in order to be able to test the file loading function in test_wordsearch.c. Please refer
to it for a sample of valid grid input.

The program is designed to display all the words (and their locations) from the "wordlist" that were found in the grid.
WARNING: THE PROGRAM MAY TAKE SEVERAL MINUTES TO EXECUTE.

For example, the sample testgrid.txt file contains the grid-

abcdq
efghw
ijkle
mcatr
qrsti
asdfo

Searching from the entire dictionary (provided by the instructor) results in the following output to the screen-

ab 0 0 R
ef 1 0 R
cat 3 1 R
at 3 2 R
st 4 2 R
ti 4 3 R
as 5 0 R
ba 0 1 L
fe 1 1 L
el 2 4 L
elk 2 4 L
ta 3 3 L
it 4 4 L
its 4 4 L
of 5 4 L
ae 0 0 D
we 1 4 D
ka 2 2 D
kas 2 2 D
er 2 4 D
as 3 2 D
io 4 4 D
ea 1 0 U
mi 3 0 U
re 3 4 U
rew 3 4 U
ire 4 4 U
oi 5 4 U