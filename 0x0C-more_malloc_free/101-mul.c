#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void populateResult(char *dest, char *n1, int n1_len, char *n2, int n2_len);
int getLengthOfNum(char *str);
void print_result(char *src, int length);

/**
 * main - entry point, multiplies two numbers
 *
 * @argc: integer, length of @argv
 *
 * @argv: one-dimensional array of strings, arguments of this program
 *
 * Return: 0, success
 */

int main(int argc, char *argv[])
{
	int num1_length, num2_length;
	char *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	num1_length = getLengthOfNum(argv[1]);

	if (!num1_length)
	{
		printf("Error\n");
		exit(98);
	}

	num2_length = getLengthOfNum(argv[2]);

	if (!num2_length)
	{
		printf("Error\n");
		exit(98);
	}

	result = malloc(num1_length + num2_length);

	if (!result)
		return (1);

	populateResult(result, argv[1], num1_length, argv[2], num2_length);

	print_result(result, num1_length + num2_length);
	printf("\n");
	free(result);

	return (0);
}

/**
 * getLengthOfNum - length of numbers in a string
 *
 * @str: pointer to string of numbers
 *
 * Return: integer (SUCCESS) or
 * NULL, if string includes char
 */

int getLengthOfNum(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return ('\0');

	}

	return (i);
}

/**
 * populateResult - multiplies two numbers stored as string
 * and stores result in @dest
 *
 * @dest: pointer to where @num1 * @num2 should be stored
 *
 * @n1: positive number stored as string in an array
 *
 * @n2: positive number stored as string in an array
 *
 * @n1_len: length of @n1
 *
 * @n2_len: length of @n2
 */

void populateResult(char *dest, char *n1, int n1_len, char *n2, int n2_len)
{
	int i, j, k, temp_value, non_carry_value;
	int carry_value = 0;
	char *multiplicand, *multiplier;

	if (n1_len > n2_len)
	{
		i = n1_len - 1;
		j = n2_len - 1;
		multiplicand = n1;
		multiplier = n2;
	}
	else
	{
		i = n2_len - 1;
		j = n1_len - 1;
		multiplicand = n2;
		multiplier = n1;
	}

	while (i >= 0)
	{
		k = i;

		while (k >= 0)
		{
			temp_value = ((multiplicand[k] - '0') * (multiplier[j] - '0'));
			temp_value += carry_value;

			if (j + 1 <= n2_len - 1 && dest[k + j + 1] >= '0' && dest[k + j + 1] <= '9')
				temp_value += dest[k + j + 1] - '0';

			if (temp_value < 10)
			{
				non_carry_value = temp_value;
				carry_value = 0;
			}
			else
			{
				non_carry_value = temp_value % 10;
				carry_value = temp_value / 10;
			}

			dest[k + j + 1] = non_carry_value + '0';
			k--;
		}

		if (carry_value)
			dest[k + j + 1] = carry_value + '0';

		carry_value = 0;

		if (j > 0)
			j--;
		else
			i = -1;
	}

	free(dest);
	free(multiplicand);
	free(multiplier);
}

/**
 * print_result - prints numbers stored as string in a memory location
 *
 * @src: pointer to memory that stores numbers as strings
 *
 * @length: length of @src
 */

void print_result(char *src, int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		if (src[i] >= '0' && src[i] <= '9')
		printf("%c", src[i]);
	}
}







#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

int find_len(char *str);
char *create_xarray(int size);
char *iterate_zeroes(char *str);
void get_prod(char *prod, char *mult, int digit, int zeroes);
void add_nums(char *final_prod, char *next_prod, int next_len);

/**
 * find_len - Finds the length of a string.
 * @str: The string to be measured.
 *
 * Return: The length of the string.
 */
int find_len(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}

/**
 * create_xarray - Creates an array of chars and initializes it with
 *                 the character 'x'. Adds a terminating null byte.
 * @size: The size of the array to be initialized.
 *
 * Description: If there is insufficient space, the
 *              function exits with a status of 98.
 * Return: A pointer to the array.
 */
char *create_xarray(int size)
{
	char *array;
	int index;

	array = malloc(sizeof(char) * size);

	if (!array)
		exit(98);

	for (index = 0; index < (size - 1); index++)
		array[index] = 'x';

	array[index] = '\0';

	return (array);
}

/**
 * iterate_zeroes - Iterates through a string of numbers containing
 *                  leading zeroes until it hits a non-zero number.
 * @str: The string of numbers to be iterate through.
 *
 * Return: A pointer to the next non-zero element.
 */
char *iterate_zeroes(char *str)
{
	while (*str && *str == '0')
		str++;

	return (str);
}

/**
 * get_digit - Converts a digit character to a corresponding int.
 * @c: The character to be converted.
 *
 * Description: If c is a non-digit, the function
 *              exits with a status of 98.
 * Return: The converted int.
 */
int get_digit(char c)
{
	int digit = c - '0';

	if (digit < 0 || digit > 9)
	{
		printf("Error\n");
		exit(98);
	}

	return (digit);
}

/**
 * get_prod - Multiplies a string of numbers by a single digit.
 * @prod: The buffer to store the result.
 * @mult: The string of numbers.
 * @digit: The single digit.
 * @zeroes: The necessary number of leading zeroes.
 *
 * Description: If mult contains a non-digit, the function
 *              exits with a status value of 98.
 */
void get_prod(char *prod, char *mult, int digit, int zeroes)
{
	int mult_len, num, tens = 0;

	mult_len = find_len(mult) - 1;
	mult += mult_len;

	while (*prod)
	{
		*prod = 'x';
		prod++;
	}

	prod--;

	while (zeroes--)
	{
		*prod = '0';
		prod--;
	}

	for (; mult_len >= 0; mult_len--, mult--, prod--)
	{
		if (*mult < '0' || *mult > '9')
		{
			printf("Error\n");
			exit(98);
		}

		num = (*mult - '0') * digit;
		num += tens;
		*prod = (num % 10) + '0';
		tens = num / 10;
	}

	if (tens)
		*prod = (tens % 10) + '0';
}

/**
 * add_nums - Adds the numbers stored in two strings.
 * @final_prod: The buffer storing the running final product.
 * @next_prod: The next product to be added.
 * @next_len: The length of next_prod.
 */
void add_nums(char *final_prod, char *next_prod, int next_len)
{
	int num, tens = 0;

	while (*(final_prod + 1))
		final_prod++;

	while (*(next_prod + 1))
		next_prod++;

	for (; *final_prod != 'x'; final_prod--)
	{
		num = (*final_prod - '0') + (*next_prod - '0');
		num += tens;
		*final_prod = (num % 10) + '0';
		tens = num / 10;

		next_prod--;
		next_len--;
	}

	for (; next_len >= 0 && *next_prod != 'x'; next_len--)
	{
		num = (*next_prod - '0');
		num += tens;
		*final_prod = (num % 10) + '0';
		tens = num / 10;

		final_prod--;
		next_prod--;
	}

	if (tens)
		*final_prod = (tens % 10) + '0';
}

/**
 * main - Multiplies two positive numbers.
 * @argv: The number of arguments passed to the program.
 * @argc: An array of pointers to the arguments.
 *
 * Description: If the number of arguments is incorrect or one number
 *              contains non-digits, the function exits with a status of 98.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *final_prod, *next_prod;
	int size, index, digit, zeroes = 0;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if (*(argv[1]) == '0')
		argv[1] = iterate_zeroes(argv[1]);
	if (*(argv[2]) == '0')
		argv[2] = iterate_zeroes(argv[2]);
	if (*(argv[1]) == '\0' || *(argv[2]) == '\0')
	{
		printf("0\n");
		return (0);
	}

	size = find_len(argv[1]) + find_len(argv[2]);
	final_prod = create_xarray(size + 1);
	next_prod = create_xarray(size + 1);

	for (index = find_len(argv[2]) - 1; index >= 0; index--)
	{
		digit = get_digit(*(argv[2] + index));
		get_prod(next_prod, argv[1], digit, zeroes++);
		add_nums(final_prod, next_prod, size - 1);
	}
	for (index = 0; final_prod[index]; index++)
	{
		if (final_prod[index] != 'x')
			putchar(final_prod[index]);
	}
	putchar('\n');

	free(next_prod);
	free(final_prod);

	return (0);
}
