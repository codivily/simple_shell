#include "main.h"


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
	size_t len = 0, i = 0, argc = 0;

	if (!str)
		return (NULL);

	/* copy str into str_ */
	while(str[i++])
		;
	len = i;

	str_ = malloc(sizeof(*str_) * (len + 1));
	if (!str_)
		return (NULL);
		
	while (i >= 0)
	{
		str_[i] = str[i];
		i--;
	}

	for(token = strtok(str_, delim); token; token = strtok(NULL, delim))
		argc += 1;
	free(str_);

	args = malloc(sizeof(*args) * (argc + 1));
	if (!args)
		return (NULL);

	i = 0;
	for (token = strtok(str, delim); token; token = strtok(NULL, delim))
		args[i++] = token;

	return (args);
}
