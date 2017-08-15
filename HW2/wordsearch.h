/* Homework 2, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
2/16/2015
443-691-8192

 */

#ifndef WORDSEARCH_H_
#define WORDSEARCH_H_

#define MAXSZ 10
#define PLACEHOLDER '9'

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

int load_grid(FILE* infile, char outgrid[][MAXSZ]);

int find_word_up(char grid[][MAXSZ], int n, char w[]);
int find_word_left(char grid[][MAXSZ], int n, char w[]);
int find_word_down(char grid[][MAXSZ], int n, char w[]);
int find_word_right(char grid[][MAXSZ], int n, char w[]);

void reverse(char word[]);
void lowercase(char word[]);

#endif // WORDSEARCH_H_
