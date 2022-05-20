#include <stddef.h>

/**
 * _strlen - return the length of a string
 * @s: A string
 *
 * Return: The length of the string
 */
size_t _strlen(char *s)
{
	size_t i = 0;

	while (s[i++])
		;
	return (i);
}
