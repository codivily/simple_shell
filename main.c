#include "main.h"
#include <string.h>

/**
 * main - Entry point
 * @argc: An integer
 * @argv: List of command line arguments
 *
 * Return: An integer
 */
int main(int argc, const char **argv)
{
	char *cmd = NULL;
	char *args[2] = {NULL, NULL};

	/* an infinite loop */
	while (1)
	{
		/* read the command from the user */
		cmd = prompt("#cisfun$ ");

		/* command args */
		args[0] = cmd;

		/* execute and check for error */
		if (execve(cmd, args, NULL) < 0)
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", argv[0]);

		/* release malloced memory from prompt function call */
		free(cmd);
	}


	return (0);
}
