/* Homework 2, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
2/16/2015
443-691-8192

*/

#include "wordsearch.h"

int load_grid(FILE* infile, char outgrid[][MAXSZ])
{
  for (int r = 0; r < MAXSZ; r++)
    {
      for (int c = 0; c < MAXSZ; c++)
	{
	  outgrid[r][c] = PLACEHOLDER;
	}
    }

  int row = 0;
  int col = -1;
  char c;
  int c_int;
  char old_c = '1';
  bool valid = true;
  int num_cols = 0;

  while (true)
    {
      c = tolower(fgetc(infile));

      c_int = c;
      if (c == ' ')
	{
	  break;
	}
      if (c == '\n' || c_int == EOF)
	{
	  if (old_c == '\n')
	    {
	      break;
	    }

	  if (row > 0 && (num_cols != col + 1))
	    {
	      valid = false;
	      break;
	    }
	  
	  if (c == EOF)
	    {
	      break;
	    }

	  num_cols = col + 1;
	  row++;
	  col = -1;
	}
      else
	{
	  col++;
	  if (col >= MAXSZ || row >= MAXSZ)
	    {
	      valid = false;
	      break;
	    }
	  outgrid[row][col] = c;
	}
      
      old_c = c;
    }
  
  if (num_cols == 0)
    { valid = false; }
  else
    {
      if (outgrid[num_cols-1][0] == PLACEHOLDER)
	{valid = false;}
      if (num_cols < 10 && outgrid[num_cols][0] != PLACEHOLDER)
	{valid = false;}
    }

  fclose(infile);

  if (valid == true)
    {
      return num_cols;
    }
  else
    {
      return 0;
    }
}

int find_word_right(char grid[][MAXSZ], int n, char w[])
{
  bool found = false;
  int len = strlen(w);
  int num_matches = 0;
  lowercase(w);
  
  for (int r = 0; r < n; r++)
    {
      for (int c = 0; c < n; c++)
	{
	  if (grid[r][c] == w[0])
	    {
	      int col2 = 0;
	      while (!found && grid[r][c + col2] == w[col2] && col2 < len && c + col2 < n)
		{
		  if (col2 == len-1 && grid[r][c + col2] == w[len - 1])
		    {
		      found = true;
		      num_matches++;
		      printf("%s %d %d R\n", w, r, c);
		    }
		  col2++;
		}
	    }
	  found = false;
	}
    }

  return num_matches;
}

void reverse(char word[])
{
  int len = strlen(word);
  char temp;
  
  for (int i = 0; i < (len/2); i++)
    {
      temp = word[i];
      word[i] = word[len-1-i];
      word[len-1-i] = temp;
    }
}

void lowercase(char word[])
{
  int len = strlen(word);
  
  for (int i = 0; i < len; i++)
    {
      word[i] = tolower(word[i]);
    }
}

int find_word_left(char grid[][MAXSZ], int n, char w[])
{
  bool found = false;
  int len = strlen(w);
  lowercase(w);
  reverse(w);
  int num_matches = 0;
  
  for (int r = 0; r < n; r++)
    {
      for (int c = 0; c < n; c++)
	{
	  if (grid[r][c] == w[0])
	    {
	      int col2 = 0;
	      while (!found && grid[r][c + col2] == w[col2] && col2 < len && c + col2 < n)
		{
		  if (col2 == len-1 && grid[r][c + col2] == w[len - 1])
		    {
		      found = true;
		      num_matches++;
		      reverse(w);
		      printf("%s %d %d L\n", w, r, c + col2);
		      reverse(w);
		    }
		  col2++;
		}
	    }
	  found = false;
	}
    }

  reverse(w);
  return num_matches;
}

int find_word_down(char grid[][MAXSZ], int n, char w[])
{
  bool found = false;
  int num_matches = 0;
  int len = strlen(w);

  lowercase(w);
  
  for (int r = 0; r < n; r++)
    {
      for (int c = 0; c < n; c++)
	{
	  if (grid[r][c] == w[0])
	    {
	      int row2 = 0;
	      while (!found && grid[r + row2][c] == w[row2] && row2 < len && r + row2 < n)
		{
		  if (row2 == len-1 && grid[r + row2][c] == w[len - 1])
		    {
		      found = true;
		      num_matches++;
		      printf("%s %d %d D\n", w, r, c);
		    }
		  row2++;
		}
	    }
	  found = false;
	}
    }

  return num_matches;
}

int find_word_up(char grid[][MAXSZ], int n, char w[])
{
  bool found = false;
  int num_matches = 0;
  int len = strlen(w);
  lowercase(w);
  reverse(w);
  
  for (int r = 0; r < n; r++)
    {
      for (int c = 0; c < n; c++)
	{
	  if (grid[r][c] == w[0])
	    {
	      int row2 = 0;
	      while (!found && grid[r + row2][c] == w[row2] && row2 < len && r + row2 < n)
		{
		  if (row2 == len-1 && grid[r + row2][c] == w[len - 1])
		    {
		      found = true;
		      num_matches++;
		      reverse(w);
		      printf("%s %d %d U\n", w, r + row2, c);
		      reverse(w);
		    }
		  row2++;
		}
	    }
	  found = false;
	}
    }
  
  reverse(w);
  return num_matches;
}
