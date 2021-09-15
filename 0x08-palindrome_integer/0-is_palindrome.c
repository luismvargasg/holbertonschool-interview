#include "palindrome.h"
#include <stdio.h>


/**
 * is_palindrome - Function that checks whether or not
 * a given unsigned integer is a palindrome.
 * @n: is the number to be checked.
 *
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
	unsigned long q = n, rem = 0, result = 0;

	while (q != 0)
	{
		rem = q % 10;
		result = result * 10 + rem;
		q = q / 10;
	}

	if (result == n)
		return (1);
	return (0);
}
