/* Homework 1, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
tagarwa2
2/9/2015
443-691-8192

 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define LENGTH 17

char binaryForm[33];

void binarize(unsigned int decimal)
{
  binaryForm[32] = '\0';
  int temp;
  int i;

  for (i = 31; i >= 0; i--)
    {
      temp = decimal >> i;
      
      if(temp & 1)
	{
	  binaryForm[31 - i] = '1';
	}
      else
	{
	  binaryForm[31 - i] = '0';
	}
    }
}

int main(int argc, char* argv[])
{
  
  if (argc == 1)
  {
    printf("Usage: Enter name of text file\n");
    return 1;  // exit program
  }

  FILE *inputFile = fopen(argv[1], "r");
  assert(inputFile != NULL);
  FILE *outputFile = fopen("courseInts.txt", "w");
  assert(outputFile != NULL);
  
  while(!feof(inputFile))
{
  
  char course[LENGTH];
  fscanf(inputFile, "%s\n", course);
  char division[3] = {course[0], course[1], '\0'};
  int divisionCode;

  if (strcmp(division,"AS") == 0)
    divisionCode = 0;
  else if (strcmp(division,"BU") == 0)
    divisionCode = 1;
  else if (strcmp(division,"ED") == 0)
    divisionCode = 2;
  else if (strcmp(division,"EN") == 0)
    divisionCode = 3;
  else if (strcmp(division,"ME") == 0)
    divisionCode = 4;
  else if (strcmp(division,"PH") == 0)
    divisionCode = 5;
  else if (strcmp(division,"PY") == 0)
    divisionCode = 6;
  else if (strcmp(division,"SA") == 0)
    divisionCode = 7;

  char department[4] = {course[3], course[4], course[5], '\0'};
  unsigned int departmentCode =  atoi(department);

  char courseNumber[4] = {course[7], course[8], course[9], '\0'};
  unsigned int courseCode = atoi(courseNumber);

  unsigned int gradeCode1;

  switch (course[10])
    {
    case 'A': gradeCode1 = 0; break;
    case 'B': gradeCode1 = 1; break;
    case 'C': gradeCode1 = 2; break;
    case 'D': gradeCode1 = 3; break;
    case 'F': gradeCode1 = 4; break;
    case 'I': gradeCode1 = 5; break;
    case 'S': gradeCode1 = 6; break;
    case 'U': gradeCode1 = 7; break;
    }

  unsigned int gradeCode2;

  switch (course[11])
    {
    case '+': gradeCode2 = 0; break;
    case '-': gradeCode2 = 1; break;
    case '/': gradeCode2 = 2; break;
    }

  unsigned int creditCode1;

  switch (course[12])
    {
    case '0': creditCode1 = 0; break;
    case '1': creditCode1 = 1; break;
    case '2': creditCode1 = 2; break;
    case '3': creditCode1 = 3; break;
    case '4': creditCode1 = 4; break;
    case '5': creditCode1 = 5; break;
    }

  unsigned int creditCode2;

  switch (course[14])
    {
    case '0': creditCode2 = 0; break;
    case '5': creditCode2 = 1; break;
    }
  
  unsigned int decimalForm = (divisionCode << 29) | (departmentCode << 19) | (courseCode << 9) | (gradeCode1 << 6) | (gradeCode2 << 4) | 
    (creditCode1 << 1) | (creditCode2);
  
  binarize(decimalForm);
  printf("%s  %u  %s\n", course, decimalForm, binaryForm);
  fprintf(outputFile, "%u\n", decimalForm);

    }
  
  fclose(outputFile);
  fclose(inputFile);
  return 0;
}
