#include "main.h"
#include <stdlib.h>

/**
 *_strdup - duplicate a string
 *@str: A string
 *
 *Return: A pointer to the duplicate string
 */
char *_strdup(const char *str)
{
	size_t i = 0;
	size_t len = 0;
	char *_str = NULL;

	while (str[i++])
	;
	len += i;

	_str = malloc(sizeof(*_str) * (len + 1));

	_memcpy(_str, str, len + 1);

	return (_str);
}

