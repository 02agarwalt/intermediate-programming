/* Homework 2, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
2/16/2015
443-691-8192

*/

#include "wordsearch.h"

void test_file_load()
{
  printf("Testing file load...\n");
  FILE* testFile = fopen("testgrid", "r");
  char testGrid[MAXSZ][MAXSZ];

  int n = load_grid(testFile, testGrid);

  if (n == 0)
    {
      printf("Invalid grid\n");
    }
  else
    {
      for (int r = 0; r < n; r++)
	{
	  for (int c = 0; c < n; c++)
	    {
	      printf("%c", testGrid[r][c]);
	      
	      if (c == n - 1)
		{
		  printf("\n");
		}
	    }
	}
    }
  printf("Number of rows and columns loaded = %d\n", n);
  assert(n == 6);
  printf("File load test successful.\n");
}

void test_find_right()
{
  char grid[5][10] = { {'f','a','d','g','h'} , {'g','c','a','t','s'} , {'h','e','l','l','o'} , {'a','s','d','f','g'} , {'b','c','d','h','t'} };
  char word[] = "cat";
  int n = 5;

  printf("Testing find right...\n");
  int x = find_word_right(grid, n, word);
  assert(x == 1);
  printf("Find right test successful.\n");
}

void test_word_reverse()
{
  printf("Testing word reversal...\n");
  char word[] = "hello";
  printf("Original word is: %s\n", word);
  reverse(word);
  printf("Reversed word is: %s\n", word);
  assert(strcmp(word, "olleh") == 0);
  reverse(word);
  printf("Double reversed word is: %s\n", word);
  assert(strcmp(word, "hello") == 0);
  printf("Word reversal successful.\n");
}

void test_find_left()
{
  char grid[5][10] = { {'f','a','d','g','h'} , {'g','s','t','a','c'} , {'h','t','a','c','o'} , {'a','s','d','f','g'} , {'b','c','d','h','t'} };
  char word[] = "cat";
  int n = 5;

  printf("Testing find left...\n");
  int x = find_word_left(grid, n, word);
  assert(x == 2);
  printf("Find left test successful.\n");
}

void test_find_down()
{
  char grid[5][10] = { {'f','a','d','g','h'} , {'g','c','a','t','s'} , {'h','e','l','l','o'} , {'a','s','d','f','g'} , {'b','c','d','h','t'} };
  char word[] = "cesc";
  int n = 5;

  printf("Testing find down...\n");
  int x = find_word_down(grid, n, word);
  assert(x == 1);
  printf("Find down test successful.\n");
}

void test_find_up()
{
  char grid[5][10] = { {'f','a','d','g','h'} , {'g','c','a','t','s'} , {'h','e','l','l','o'} , {'a','s','d','f','g'} , {'b','c','d','h','t'} };
  char word[] = "dla";
  int n = 5;

  printf("Testing find up...\n");
  int x = find_word_up(grid, n, word);
  assert(x == 1);
  printf("Find up test successful.\n");
}

void test_lowercase()
{
  char word[] = "TANAY";
  printf("Testing lowercase function...\n");
  lowercase(word);
  printf("%s\n", word);
  assert(strcmp(word, "tanay") == 0);
  printf("Test successful.\n");
}

int main(void)
{
  test_file_load();
  test_word_reverse();
  test_find_right();
  test_find_left();
  test_find_down();
  test_find_up();
  test_lowercase();
  return 0;
}
