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
	int ok = 0;

	/* an infinite loop */
	while (1)
	{
		/* read the command from the user */
		cmd = prompt("#cisfun$ ");

		/* command args */
		args[0] = cmd;

		/* execute and check for error */
		ok = execve(cmd, args, NULL);
		if (ok == -1)
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", argv[0]);

		/* release malloced memory from prompt function call */
		free(cmd);
	}


	return (0);
}
