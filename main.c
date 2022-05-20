#include "main.h"
#include <stdlib.h>
#include <unistd.h>


/**
 * on_signal - catch signals
 * @sig: A integer
 *
 * Return: void
 */
void on_signal(int sig)
{
	(void) sig;
}

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
	size_t cmd_size = 0;
	char _cmd[128];
	char **args = NULL;
	int status = 0;
	int piped = !isatty(STDIN_FILENO);

	signal(SIGINT, on_signal);
	while (1)
	{
		if (piped)
		{
			_getline(&cmd, &cmd_size, STDIN_FILENO);
			if (!cmd)
				break;
		}
		else if (argc > 1)
			args = argv + 1;
		else
		{
			write(STDOUT_FILENO, "#cisfun$ ", 11);
			_getline(&cmd, &cmd_size, STDIN_FILENO);
			if (!cmd)
			{
				free(cmd);
				cmd = NULL;
				dprintf(STDERR_FILENO, "%s: No such file or directory\n", *argv);
				continue;
			}
		}
		_memcpy(_cmd, cmd, _strlen(cmd) + 1);
		free(cmd);
		cmd = NULL;
		args = to_args(_cmd);
		status = exec_cmd(args, *argv);
		if (argc > 1)
			exit(status);
	}

	return (0);
}

