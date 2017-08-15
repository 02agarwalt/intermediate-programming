/* Homework 0, 600.120 Spring 2015

Tanay Agarwal
tagarwa2@jhu.edu
2/4/2015

 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 17

int main(int argc, char* argv[])
{
  char course[LENGTH];
  if (argc == 1)
  {
    printf("Usage: hw0 XX.###.###Gg#.#\n");
    return 1;  // exit program
  }

  strncpy(course, argv[1], LENGTH);  // copy to course string
  course[LENGTH-1] = '\0';   // make sure last character is null
  printf("Course string: %s\n", course);  // echo input

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
  int departmentCode =  atoi(department);

  char courseNumber[4] = {course[7], course[8], course[9], '\0'};
  int courseCode = atoi(courseNumber);

  int gradeCode1;

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

  int gradeCode2;

  switch (course[11])
    {
    case '+': gradeCode2 = 0; break;
    case '-': gradeCode2 = 1; break;
    case '/': gradeCode2 = 2; break;
    }

  int creditCode1;

  switch (course[12])
    {
    case '0': creditCode1 = 0; break;
    case '1': creditCode1 = 1; break;
    case '2': creditCode1 = 2; break;
    case '3': creditCode1 = 3; break;
    case '4': creditCode1 = 4; break;
    case '5': creditCode1 = 5; break;
    }

  int creditCode2;

  switch (course[14])
    {
    case '0': creditCode2 = 0; break;
    case '5': creditCode2 = 1; break;
    }

  printf("Division: %d\n", divisionCode);
  printf("Department: %03d\n", departmentCode);
  printf("Course: %03d\n", courseCode);
  printf("Grade: %d %d\n", gradeCode1, gradeCode2);
  printf("Credits: %d %d\n", creditCode1, creditCode2);

  return 0;
}
