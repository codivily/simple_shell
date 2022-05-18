#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 *main - Entry point
 *@argc: An integer
 *@argv: List of command line arguments
 *
 *Return: An integer
 */
int main(int argc, char **argv)
{
	char *cmd = NULL;
	char **args = NULL;
	int status = 0;
	int piped = !isatty(STDIN_FILENO);

	while (1)
	{
		if (piped)
		{
			cmd = _getline(STDIN_FILENO);
			if (!cmd)
				break;
		}
		else if (argc > 1)
			args = argv + 1;
		else
		{
			write(STDOUT_FILENO, "#cisfun$ ", 10);
			cmd = _getline(STDIN_FILENO);
			if (!cmd)
			{
				dprintf(STDERR_FILENO, "%s: No such file or directory", *argv);
				continue;
			}
		}
		args = to_args(cmd);
		status = exec_cmd(args, *argv);
		free(cmd);
		cmd = NULL;
		if (argc > 1)
			exit(status);
	}

	return (0);
}
