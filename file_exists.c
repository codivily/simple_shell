#include "main.h"
#include <sys/stat.h>

/**
 *file_exists - check if file
 *@filepath: A string
 *
 *Return: 1 if exists else 0
 */
int file_exists(const char *filepath)
{
	struct stat buffer;

	if (stat(filepath, &buffer) == 0)
		return (1);

	return (0);
}
