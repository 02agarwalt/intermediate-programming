/*
Homework 3, 600.120 Spring 2015

Tanay Agarwal and Nirmal Krishnan
tagarwa2@jhu.edu
nkrishn9@jhu.edu
tagarwa2
nkrishn9
2/27/2015
443-691-8192 - Tanay
330-840-0368 - Nirmal
*/

#ifndef WORDSEARCH_H_
#define WORDSEARCH_H_

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

void check_grid(FILE* infile, int * rows, int * cols);
void load_grid(FILE* infile, char *** outgrid, int * rows, int * cols);
int load_dict(char *** dictionary);
bool compare(char * word, char *** dictionary, int numWords);
int search_grid(char *** grid, int * rows, int * cols, char *** dictionary, int numWords);

#endif // WORDSEARCH_H_
