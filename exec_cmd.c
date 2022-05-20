#include "main.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 *exec_cmd - execute command from args
 *@args: command arguments
 *@shell_path: A string
 *
 *Return: status (An integer)
 */
int exec_cmd(char **args, char *shell_path)
{
	int status = 0;
	int err_code = 0;
	char cmd_path[257];
	char *cmd = NULL;

	/*builtin */
	if (_strcmp(*args, "exit") == 0)
		_exit_(args);

	if (_strcmp(*args, "env") == 0)
		_printenv();
	else
	{
		cmd = locate(*args);
		if (cmd == NULL)
		{
			print_error(shell_path, ": No such file or directory\n");
			return (status);
		}
		_memcpy(cmd_path, cmd, _strlen(cmd) + 1);
		free(cmd);
		*args = cmd_path;
		if (fork() == 0)
		{
			err_code = execve(*args, args, environ);
			print_error(shell_path, ": No such file or directory\n");
			free(cmd);
			free(args);
			exit(err_code);
		}
		else
			wait(&status);
	}

	free(args);
	return (status);
}

