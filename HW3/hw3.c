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

int main(int argc, char* argv[])
{
  
  if (argc == 1)
  {
    printf("Usage: Enter name of grid file\n");
    return 1;  // exit program
  }

  FILE* gridFile = fopen(argv[1], "r");
  assert(gridFile != NULL);
  
  int rows = 0;
  int cols = 0;
  char ** grid;
  check_grid(gridFile, &rows, &cols); //check grid
  fclose(gridFile);
  if (rows == 0 && cols == 0) //check if grid is valid
    {
      printf("Invalid grid.\n");
      return 1;
    }
  gridFile = fopen(argv[1], "r");
  load_grid(gridFile, &grid, &rows, &cols); //load grid
  fclose(gridFile);
   
  char ** dictionary;
  int numWords = load_dict(&dictionary); //load dictionary
  
  search_grid(&grid, &rows, &cols, &dictionary, numWords); //perform word search

  //free allocated memory
  for (int i = 0; i < numWords; i++)
    {
      free(dictionary[i]);
    }
  free (dictionary);
  
  for (int i = 0; i < rows; i++)
    {
      free(grid[i]);
    }
  free (grid);
}
