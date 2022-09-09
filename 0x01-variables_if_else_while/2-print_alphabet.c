#include <stdio.h>

#include <ctype.h>
/**
 * main - main block
 * Description: Get a random number and print the number
 * positive,nagetive or zero
 * Return: Always 0 (success)
 */
int main(void)
{
  int alphabet;
  
  for (alphabet ='a'; alphabet <=z; alphabet++)
  {
    alphabet = tolower(alphabet);
    putchar(alphabet);
  }
  putchar('\n');
  return (0);
}
