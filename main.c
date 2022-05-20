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
	ssize_t cmd_len = 0;
	char **args = NULL;
	int status = 0;
	int piped = !isatty(STDIN_FILENO);

	signal(SIGINT, on_signal);
	while (1)
	{
		if (argc > 1)
		{
			status = exec_cmd(argv + 1, *argv);
			exit(status);
		}

		if (!piped)
			write(STDOUT_FILENO, "#cisfun$ ", 10);
		cmd_len = _getline(&cmd, &cmd_size, STDIN_FILENO);
		if (cmd[0] == '\n' || cmd[0] == '\0')
		{
			free(cmd);
			cmd = NULL;
			print_error(*argv, ": No such file or directory\n");
			continue;
		}
		cmd[cmd_len - 1] = '\0';
		_memcpy(_cmd, cmd, _strlen(cmd) + 1);
		free(cmd);
		cmd = NULL;
		args = to_args(_cmd);
		status = exec_cmd(args, *argv);
	}
	return (0);
}

