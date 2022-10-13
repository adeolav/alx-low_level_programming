#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns sum of all its parameters
 * @n: number of param to be passed
 *
 * Return: the sum
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0;
	unsigned int i;
	va_list num_list;

	va_start(num_list, n);

	for (i = 0; i < n ; i++)
		sum += va_arg(num_list, int);
	va_end(num_list);
	return (sum);
}
