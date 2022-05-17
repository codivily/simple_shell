#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - Entry point
 * @argc: An integer
 * @argv: List of command line arguments
 *
 * Return: An integer
 */
int main(int argc, char **argv)
{
	char *cmd_str = NULL;
	char **args = NULL;
	int exit_code = 0;
	int status = 0;

	/* an infinite loop */
	while (1)
	{
		/* command line args support */
		if (argc > 1)
			args = argv + 1;
		else
		{
			/* prompt the user  to enter command */
			cmd_str = prompt("#cisfun$ ");
			/* command args */
			args = to_args(cmd_str);
		}

		*args = locate(*args);
		/* run the command in a child process */
		if (*args)
		{
			if(fork() == 0)
			{
				exit_code = execve(*args, args, NULL);
				dprintf(STDERR_FILENO, "%s: No such file or directory\n", cmd_str);
				free(cmd_str);
				exit(exit_code);
			}
			wait(&status);
		}
		else
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", cmd_str);

		free(cmd_str);
		if (argc > 1)
			exit(status);
	}


	return (0);
}
