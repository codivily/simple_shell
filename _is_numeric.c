#include <stddef.h>

/**
 *_is_numeric - check if string is numeric
 *@str: A string
 *
 *Return: 1 if numeric else 0
 */
int _is_numeric(const char *str)
{
	size_t i = 0;
	char c = 0;

	if (!str)
		return (0);

	if (str[i] == '+' || str[i] == '-')
		i++;

	do {
		c = str[i++];
	} while ('0' <= c && c <= '9');

	return (c == '\0' ? 1 : 0);
}
