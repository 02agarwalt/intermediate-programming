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

#include "wordsearch.h"

void test_grid_check_and_load()
{
  FILE * infile = fopen("testgrid.txt", "r");
  int rows = 0;
  int cols = 0;
  char ** grid;
  check_grid(infile, &rows, &cols);
  fclose(infile);
  assert(rows == 6);
  assert(cols == 5);
  infile = fopen("testgrid.txt", "r");
  load_grid(infile, &grid, &rows, &cols);
  fclose(infile);
  assert(grid[3][0] == 'm');
}

void test_compare()
{
  char ** dictionary = malloc(5*sizeof(char*));
  dictionary[0] = "hello";
  dictionary[1] = "my";
  dictionary[2] = "name";
  dictionary[3] = "is";
  dictionary[4] = "tanay";
  int numWords = 5;
  assert(compare("my", &dictionary, numWords));
  free(dictionary);
}

void test_grid_search()
{
  char ** dictionary = malloc(5 * sizeof(char*));
  dictionary[0] = "hello";
  dictionary[1] = "my";
  dictionary[2] = "name";
  dictionary[3] = "is";
  dictionary[4] = "tanay";
  int rows = 4;
  int cols = 5;
  int numWords = 5;
  char ** grid = malloc(4 * sizeof(char*));
  grid[0] = "hello";
  grid[1] = "asdfg";
  grid[2] = "asdfg";
  grid[3] = "asdfg";
  int numWordsFound = search_grid(&grid, &rows, &cols, &dictionary, numWords);
  free(grid);
  free(dictionary);
  assert(numWordsFound == 1);
}

int main(void)
{
  test_grid_check_and_load();
  test_compare();
  test_grid_search();
}
