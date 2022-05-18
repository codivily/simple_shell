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
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t n_chars = 0;

	/* display the prompt message */
	printf("%s", msg);
	/* wait for user input */
	n_chars = getline(&buffer, &buffer_size, stdin);
	if (!buffer)
	{
		perror("getline error");
		exit(1);
	}

	/* remove the '\n' char with a null character */
	buffer[n_chars - 1] = '\0';

	return (buffer);
}
