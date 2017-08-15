/* Homework 2, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
2/16/2015
443-691-8192

 */

#include "wordsearch.h"

int main(int argc, char* argv[])
{
  
  if (argc == 1)
  {
    printf("Usage: Enter name of text file\n");
    return 1;  // exit program
  }

  FILE* inputFile = fopen(argv[1], "r");
  assert(inputFile != NULL);

  char grid[MAXSZ][MAXSZ];
  int n = load_grid(inputFile, grid);

  if (n == 0)
    {
      printf("Invalid grid file.\n");
      return 1;
    }
  
  char inputWord[100];

  while (scanf(" %s[^ \t\nEOF]%*c", inputWord) && !feof(stdin))
    {      
      int a = find_word_right(grid, n, inputWord);
      int b = find_word_left(grid, n, inputWord);
      int c = find_word_up(grid, n, inputWord);
      int d = find_word_down(grid, n, inputWord);
      if (a+b+c+d == 0)
	printf("%s - Not Found\n", inputWord);
    }
}
