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

char userChoice;
int quitClause = 0;
int courseCount = 0;
unsigned int intList[2500];

void printMenu()
{
  printf("\n");
  printf("n - display the total number of courses\n");
  printf("d - list all courses from a particular department\n");
  printf("l - list all courses with a particular letter grade\n");
  printf("c - list all courses with at least a specified number of credits\n");
  printf("g - compute the GPA of all the courses with letter grades\n");
  printf("q - quit the program\n");
  printf("Enter letter choice -> ");
  scanf("%c", &userChoice);
  char placeholder = getchar();

  if(userChoice == '\n')
    {
      userChoice = placeholder;
    }
}

void choiceD();
void choiceL();
void choiceC();
void computeGPA();

void interpretChoice(char choice)
{
  switch(choice)
    {
    case 'q': quitClause = 1; break;
    case 'n': printf("Number of courses = %d\n", courseCount); break;
    case 'd': choiceD(); break;
    case 'l': choiceL(); break;
    case 'c': choiceC(); break;
    case 'g': computeGPA(); break;
    }
}

int main(void)
{

  FILE *inputFile = fopen("courseInts.txt", "r");
  assert(inputFile != NULL);

  while (!feof(inputFile))
    {
      fscanf(inputFile, "%u\n", &intList[courseCount]);
      courseCount++;
    }

  while (quitClause != 1)
    {
      printMenu();
      interpretChoice(userChoice);
    }

  fclose(inputFile);
  return 0;
}

void decode(unsigned int encodedInt)
{
  switch(encodedInt >> 29)
    {
    case 0: printf("AS."); break;
    case 1: printf("BU."); break;
    case 2: printf("ED."); break;
    case 3: printf("EN."); break;
    case 4: printf("ME."); break;
    case 5: printf("PH."); break;
    case 6: printf("PY."); break;
    case 7: printf("SA."); break;
    }

  unsigned int dep = (encodedInt << 3) >> 22;
  printf("%03u.", dep);
  unsigned int cou = (encodedInt << 13) >> 22;
  printf("%03u", cou);

  switch( (encodedInt << 23) >> 29 )
    {
    case 0: printf("A"); break;
    case 1: printf("B"); break;
    case 2: printf("C"); break;
    case 3: printf("D"); break;
    case 4: printf("F"); break;
    case 5: printf("I"); break;
    case 6: printf("S"); break;
    case 7: printf("U"); break;
    }

  switch( (encodedInt << 26) >> 30 )
    {
    case 0: printf("+"); break;
    case 1: printf("-"); break;
    case 2: printf("/"); break;
    }

  unsigned int cred1 = (encodedInt << 28) >> 29;
  unsigned int cred2 = ((encodedInt << 31) >> 31) * 5;

  printf("%u.%u\n", cred1, cred2);
}

void choiceD()
{
  unsigned int departmentNumber;
  printf("Enter the department number -> ");
  scanf("%u", &departmentNumber);
  getchar();
  for (int i = 0; i < courseCount; i++)
    {
      if( (((0b1111111111 << 19) & intList[i]) >> 19) == departmentNumber )
	{
	  decode(intList[i]);
	}
    }
}

void choiceL()
{
  char grade1;
  char grade2;
  printf("Enter the grade (including +, -, or /) -> ");
  scanf("%c%c", &grade1, &grade2);
  getchar();

  unsigned int grade1int;
  unsigned int grade2int;

  switch(grade1)
    {
    case 'A': grade1int = 0; break;
    case 'B': grade1int = 1; break;
    case 'C': grade1int = 2; break;
    case 'D': grade1int = 3; break;
    case 'F': grade1int = 4; break;
    case 'I': grade1int = 5; break;
    case 'S': grade1int = 6; break;
    case 'U': grade1int = 7; break;
    }
  switch(grade2)
    {
    case '+': grade2int = 0; break;
    case '-': grade2int = 1; break;
    case '/': grade2int = 2; break;
    }

  for (int i = 0; i < courseCount; i++)
    {
      if( (((7 << 6) & intList[i]) >> 6) == grade1int )
	{
	  if( (((3 << 4) & intList[i]) >> 4) == grade2int )
	    {
	      decode(intList[i]);
	    }
    	}
    }
}

void choiceC()
{
  unsigned int cred1;
  unsigned int cred2;
  unsigned int cred2code;
  printf("Enter the number of credits -> ");
  scanf("%u.%u", &cred1, &cred2);
  getchar();

  if(cred2 == 0)
    cred2code = 0;
  if(cred2 == 5)
    cred2code = 1;

  for (int i = 0; i < courseCount; i++)
    {
      if( ((intList[i] << 28) >> 29) == cred1)
	{
	  if( ((intList[i] << 31) >> 31) >= cred2code)
	    {
	      decode(intList[i]);
	    }
	}

      if( ((intList[i] << 28) >> 29) > cred1)
	{
	  decode(intList[i]);
	}
    }
}

void computeGPA()
{
  int j = 0;
  unsigned int newIntList[2500];
  for (int i = 0; i < courseCount; i++)
    {
      if( (((7 << 6) & intList[i]) >> 6) < 5 )
	{
	  newIntList[j] = intList[i];
	  j++;
	}
    }
  
  double totalScore = 0;
  double totalCredits = 0;

  for (int x = 0; x < j; x++)
    {
      unsigned int gradeCode = ((7 << 6) & newIntList[x]) >> 6;
      double gradeScore = 4 - gradeCode;

      switch( ((3 << 4) & newIntList[x]) >> 4 )
	{
	case 0: gradeScore = gradeScore + 0.3; break;
	case 1: gradeScore = gradeScore - 0.3; break;
	}
      
      double newGradeScore;
      float epsilon = 0.0001;

      if (fabs(gradeScore - 4.3) < epsilon)
	{newGradeScore = 4.0;}

      else if (fabs(gradeScore - 0.7) < epsilon)
	{newGradeScore = 1.0;}

      else if (fabs(gradeScore - 0.3) < epsilon || fabs(gradeScore + 0.3) < epsilon)
	{newGradeScore = 0.0;}

      else
	{newGradeScore = gradeScore;}

      unsigned int credits1 = (newIntList[x] << 28) >> 29;
      unsigned int credits2 = (newIntList[x] << 31) >> 31;
      double credits = (double) credits1 + ((double) credits2*0.5);

      double courseScore = newGradeScore * credits;
      totalScore = totalScore + courseScore;
      totalCredits = totalCredits + credits;
    }
  
  double gpa = totalScore/totalCredits;
  printf("GPA = %.3f\n", gpa);
}
