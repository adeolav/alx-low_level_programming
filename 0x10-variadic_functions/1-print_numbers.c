#include "variadic_functions.h"

#include <stdio.h>

#include <stdarg.h>













/**
 * print_numbers - prints numbers followed by newline
 * @separator: string to be printed between numbers
 * @n: number of ints to be passed
 */
void print_numbers(const char *separator, const unsigned int n, ...)

{

	va_start(nums, n);


	unsigned int index;

	va_start(list, n);

	for (i = 0; i < n; i++)
	{
		/*check if separator is not null*/
		if (!separator)
			printf("%d", va_arg(list, int));
		else if (separator && i == 0)
			printf("%d", va_arg(list, int));
		else
			printf("%s%d",  separator, va_arg(list, int));
	}

	va_end(list);

	printf("\n");
}
