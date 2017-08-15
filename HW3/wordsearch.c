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

void check_grid(FILE* infile, int * rows, int * cols) //goes through grid file and gets number of rows and cols
{
  *rows = 0;
  *cols = 0;
  int tmpCols = 0;

  while(!feof(infile))
    {
      char c = fgetc(infile);
      
      if (c == '\n' && tmpCols > 0)
	{
	  if (*cols == 0)
	    {
	      (*cols) = tmpCols;
	    }
	  if (tmpCols && *cols != tmpCols)
	    {
	      (*rows) = 0;
	      (*cols) = 0;
	      return; //returns if there are differing number of elements in rows
	    }
	  tmpCols = 0;
	  *rows = *rows + 1;
	}
      else if (isalnum(c))
	{
	  tmpCols++;
	}
    }
}

void load_grid(FILE* infile, char *** outgrid, int * rows, int * cols) //goes through grid file and loads data into 2d array
{
  char ** tempArray = malloc((*rows) * sizeof(char*)); //temporary 2d array

  for(int r = 0; r < (*rows); r++)
    {
      tempArray[r] = malloc((*cols) * sizeof(char));
    }

  *outgrid = tempArray; //re-assigning pointer to our desired grid

  for (int r = 0; r < (*rows); r++) //load data into grid (obtained from hw2 solutions)
    {
      for (int c = 0; c < (*cols); c++)
	{
	  char ch = tolower(fgetc(infile));
	  if (ch == '\n')
	    {
	      ch = tolower(fgetc(infile));
	    }
	  (*outgrid)[r][c] = ch;
	}
    }
}

int load_dict(char *** dictionary) //loads word list into array of strings and then sorts
{
  int dictSize = 5;
  *dictionary = malloc(dictSize * sizeof(char*));
  int numWords = 0;  
  
  while(!feof(stdin))
    {
      int bufferSize = 5;
      int numChars = 0;
      char * buffer = malloc(bufferSize * sizeof(char));
      char ch;
      while((ch = tolower(fgetc(stdin))) != '\n' && !feof(stdin) && ch != ' ' && ch != '\t') //loads words character-by-character
	{
	  if (numChars == bufferSize - 1)
	    {
	      bufferSize = bufferSize * 2;
	      buffer = realloc(buffer, bufferSize * sizeof(char));
	    }
	  buffer[numChars] = ch;
	  numChars++;
	}
      buffer[numChars] = '\0';
      
      int length = strlen(buffer);
      
      if(length > 0) //skips whitespace
	{
	  if (numWords >= dictSize)
	    {
	      dictSize = dictSize * 2;
	      *dictionary = realloc((*dictionary), dictSize * sizeof(char*));
	    }
      
	  (*dictionary)[numWords] = malloc((length+1) * sizeof(char));
	  strcpy((*dictionary)[numWords], buffer);
	  numWords++;
	}
      
      free(buffer);
    }
  
  for (int i = 0; i < numWords; i++) //selection sort
    {
      for (int j = i+1; j < numWords; j++)
	{
	  if( strcmp( (*dictionary)[i], (*dictionary)[j] ) > 0 )
	    {
	      char * temp = malloc( (strlen((*dictionary)[i])+1) * sizeof(char) );
	      strcpy(temp, (*dictionary)[i]);
	      (*dictionary)[i] = realloc( (*dictionary)[i], (strlen((*dictionary)[j])+1) * sizeof(char) );
	      strcpy( (*dictionary)[i], (*dictionary)[j] );
	      (*dictionary)[j] = realloc( (*dictionary)[j], (strlen(temp)+1) * sizeof(char) );
	      strcpy( (*dictionary)[j], temp );
	      free(temp);
	    } 
	}
    }

  return numWords; //number of words in word list
}

bool compare(char * word, char *** dictionary, int numWords) //checks if given word is in the word list
{
  int first = 0;
  int last = numWords - 1;
  int middle = (first + last)/2;

  while (first <= last) //binary search
    {
      if ( strcmp((*dictionary)[middle], word) < 0 )
	{
	  first = middle + 1;
	}
      else if ( strcmp((*dictionary)[middle], word) == 0 )
	{
	  return true;
	}
      else
	{
	  last = middle - 1;
	}
      
      middle = (first + last)/2;
    }
  
  if (first > last)
    {
      return false;
    }
  
  return true;
}

int search_grid(char *** grid, int * rows, int * cols, char *** dictionary, int numWords) //generates every possible word and prints results
{
  int numWordsFound = 0;
  
  //search right
  for (int i = 0; i < (*rows); i++) //goes through every row
    {
      for (int j = 0; j < (*cols); j++) //goes through every column
	{
	  for (int lengthCounter = 1; lengthCounter <= (*cols) - j; lengthCounter++) //gets every possible word in each row
	    {
	      char * word = calloc( lengthCounter + 1, sizeof(char) );
	      
	      for (int charPos = 0; charPos < lengthCounter; charPos++) //loads word into buffer
		{
		  word[charPos] = (*grid)[i][j + charPos];
		}
	      word[lengthCounter] = '\0';

	      if (compare(word, dictionary, numWords) == true) //checks if word is in the word list
		{
		  printf("%s %d %d R\n", word, i, j);
		  numWordsFound++;
		}

	      free(word);
	    }
	}
    }

  //search left
  for (int i = 0; i < (*rows); i++)
    {
      for (int j = 0; j < (*cols); j++)
	{
	  for (int lengthCounter = 1; lengthCounter <= j + 1; lengthCounter++)
	    {
	      char * word = calloc( lengthCounter, sizeof(char) );
	      
	      for (int charPos = 0; charPos < lengthCounter; charPos++)
		{
		  word[charPos] = (*grid)[i][j - charPos];
		}

	      if (compare(word, dictionary, numWords) == true)
		{
		  printf("%s %d %d L\n", word, i, j);
		  numWordsFound++;
		}

	      free(word);
	    }
	}
    }

  //search down
  for (int i = 0; i < (*rows); i++)
    {
      for (int j = 0; j < (*cols); j++)
	{
	  for (int lengthCounter = 1; lengthCounter <= (*rows) - i; lengthCounter++)
	    {
	      char * word = calloc( lengthCounter, sizeof(char) );
	      
	      for (int charPos = 0; charPos < lengthCounter; charPos++)
		{
		  word[charPos] = (*grid)[i + charPos][j];
		}

	      if (compare(word, dictionary, numWords) == true)
		{
		  printf("%s %d %d D\n", word, i, j);
		  numWordsFound++;
		}

	      free(word);
	    }
	}
    }

  //search up
  for (int i = 0; i < (*rows); i++)
    {
      for (int j = 0; j < (*cols); j++)
	{
	  for (int lengthCounter = 1; lengthCounter <= i + 1; lengthCounter++)
	    {
	      char * word = calloc( lengthCounter, sizeof(char) );
	      
	      for (int charPos = 0; charPos < lengthCounter; charPos++)
		{
		  word[charPos] = (*grid)[i - charPos][j];
		}

	      if (compare(word, dictionary, numWords) == true)
		{
		  printf("%s %d %d U\n", word, i, j);
		  numWordsFound++;
		}

	      free(word);
	    }
	}
    }

  return numWordsFound; //number of words found in grid
}
