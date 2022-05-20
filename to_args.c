#include "main.h"
#include <stdio.h>


/**
 * to_args - split a string into array of command args
 * @str: A string
 *
 * Return: An array of arguments
 */
char **to_args(char *str)
{
	char **args = NULL;
	char *token = NULL, *delim = " ", *str_ = NULL;
	size_t i = 0, argc = 0;

	if (!str)
		return (NULL);

	str_ = _strdup(str);

	for (token = strtok(str_, delim); token; token = strtok(NULL, delim))
		argc += 1;
	free(str_);
	str_ = NULL;

	args = malloc(sizeof(*args) * (argc + 1));
	if (!args)
	{
		perror("malloc failed");
		exit(1);
	}
	args[argc] = NULL;
	i = 0;
	for (token = strtok(str, delim); token; token = strtok(NULL, delim))
		args[i++] = token;

	return (args);
}

