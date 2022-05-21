#include "holberton.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two positive numbers
 *
 * @argc: cuantity of numbers to multiply
 * @argv: numbers to multiply
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int number1_length, number2_length;
	char *mult_res;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}

	number1_length = check_datatype(argv[1]);
	number2_length = check_datatype(argv[2]);

	if (number1_length == -1 || number2_length == -1)
	{
		_print("Error");
		exit(98);
	}

	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		_print("0");
		return (0);
	}

	if (number1_length >= number2_length)
	{
		mult_res = multiply(argv[1], argv[2], number1_length, number2_length);
	}
	else
	{
		mult_res = multiply(argv[2], argv[1], number2_length, number1_length);
	}

	if (mult_res[0] == '0')
		_print(mult_res + 1);
	else
		_print(mult_res);

	free(mult_res);
	return (0);
}

/**
 * check_datatype - check digits
 *
 * @element: pointer to the first character
 *
 * Return: lenth of the characters if valid or -1 if not.
 */
int check_datatype(char *element)
{
	int len = 0;

	while (*element != '\0')
	{
		if (*element >= 48 && *element <= 57)
		{
			len += 1;
		}
		else
		{
			return (-1);
		}

		element += 1;
	}

	return (len);
}

/**
 * multiply - multiplies
 *
 * @n1: number1
 * @n2: number2
 * @n1_length: length of numumber1
 * @n2_length: length of number2
 *
 * Return: miltiply
 */
char *multiply(char *n1, char *n2, int n1_length, int n2_length)
{
	int idx;
	int idx2;
	int aux;
	char *multiplication_result = _malloc(n1_length + n2_length);

	for (idx = n1_length - 1; idx >= 0; idx--)
	{
		aux = 0;
		for (idx2 = n2_length - 1; idx2 >= 0; idx2--)
		{
			aux += (n1[idx] - '0') * (n2[idx2] - '0');
			aux += multiplication_result[idx + idx2 + 1] - '0';
			multiplication_result[idx + idx2 + 1] = (aux % 10) + '0';
			aux /= 10;
		}

		if (aux)
		{
			multiplication_result[idx + idx2 + 1] = (aux % 10) + '0';
		}
	}

	return (multiplication_result);
}

/**
 * _print - print
 *
 * @string: string
 */
void _print(char *string)
{
	while (*string != '\0')
	{
		_putchar(*string);
		string += 1;
	}

	_putchar('\n');
}


/**
 * _malloc - allocate space on memory
 *
 * @len: length of the array
 *
 * Return: pointer to memory allocated
 */
char *_malloc(int len)
{
	int i;

	char *res = malloc(len);

	if (!res)
	{
		_print("Error\n");
		exit(98);
	}

	for (i = 0; i < len; i++)
	{
		res[i] = '0';
	}

	return (res);
}
