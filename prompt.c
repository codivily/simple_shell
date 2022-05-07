#include "main.h"
#include <stdio.h>

/**
 * prompt - read user command and return a string
 * @msg: the prompt message
 *
 * Return: A pointer the a string
 */
char *prompt(const char *msg)
{
	char *buffer;
	size_t buffer_size = 32;

	buffer = malloc(sizeof(*buffer) * buffer_size);
	if (buffer == NULL)
	{
		perror("unable to allocate buffer");
		exit(1);
	}

	printf("%s", msg);
	getline(&buffer, &buffer_size, stdin);

	return (buffer);
}
