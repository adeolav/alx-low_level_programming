#include <stdio.h>

#include <ctype.h>
/**
 * main - main block
 * Description: Get a random number and print the number
 * positive,negative or zero
 * Return: Always 0 (success)
 */
int main(void)
{
	int letters;

	for (letters = 'a'; letters <= 'z'; letters++)
	{
		if (letters  == 'q' || letters == 'e')
		{
			continue;
		}
		putchar(letters);
	}
	putchar('\n');
	return (0);
}
