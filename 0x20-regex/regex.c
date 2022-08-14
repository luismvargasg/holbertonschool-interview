#include "regex.h"

/**
 * regex_match - Function that checks whether a given pattern matches
 * a given string.
 *
 * @str: is the string to scan.
 * @pattern: is the regluar expression.
 *
 * Return: if the pattern matches the string, or 0 if it doesn’t.
 */
int regex_match(char const *str, char const *pattern)
{
	int d = 0;
	int r = 0;

	if (!str || !pattern)
		return (0);

	d = *str && (*str == *pattern || *pattern == '.');
	r = *(pattern + 1) == '*';

	if (!*str && !r)
		return (*pattern ? 0 : 1);
	else if (d && r)
		return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
	else if (d && !r)
		return (regex_match(str + 1, pattern + 1));
	else if (r)
		return (regex_match(str, pattern + 2));
	return (0);
}
