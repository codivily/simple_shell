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
	char *cmd_str = NULL;
	char **args = NULL;

	/* an infinite loop */
	while (1)
	{
		/* read the command from the user */
		cmd_str = prompt("#cisfun$ ");

		/* command args */
		args = to_args(cmd_str);

		/* execute and check for error */
		execve(args[0], args, NULL);

		dprintf(STDERR_FILENO, "%s: No such file or directory\n", argv[0]);

		/* release malloced memory from prompt function call */
		free(cmd_str);

	}


	return (0);
}
