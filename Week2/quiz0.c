#include <stdio.h>
#include <string.h>

void reverse(char str[])
{
  int len = strlen(str);
  int back;
  int front;
  char temp;
  for (front = 0, back = len - 1; front < back; front++, back--)
    {
      temp = str[front];
      str[front] = str[back];
      str[back] = temp;
    }
}

int main(void)
{
  char line[100];
  printf("enter a word to reverse: ");
  scanf("%s", line);
  printf("you entered: %s\n", line);
  reverse(line);
  printf("reverse is: %s\n", line);
}
