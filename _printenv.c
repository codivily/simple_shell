#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 *_printenv - print the environment variables
 *
 *Return: void
 */
void _printenv(void)
{
	size_t i = 0;
	char *s = NULL;
	char line_break = '\n';
	size_t k = 0;

	while (environ[i])
	{
		s = environ[i++];
		k = 0;
		while (s[k++])
		;
		write(STDOUT_FILENO, s, k);
		write(STDOUT_FILENO, &line_break, 1);
	}
}
