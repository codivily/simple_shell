#include "main.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *locate - locate an executable from the path
 *@name: A string
 *
 *Return: the full path of the executable
 */
char *locate(const char *name)
{
	char *path = NULL;
	char *dir_path = NULL;
	char *file_path = NULL;

	if (file_exists(name))
		return (_strdup(name));

	path = _getenv("PATH");

	if (path)
		path = _strdup(path);
	else
		return (NULL);


	strtok(path, "=");
	dir_path = strtok(NULL, ":");
	while (dir_path)
	{
		file_path = join_paths('/', dir_path, name);
		if (file_exists(file_path))
			break;

		free(file_path);
		file_path = NULL;

		dir_path = strtok(NULL, ":");
	}

	free(path);

	return (file_path);
}

