#include "main.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 *exec_cmd - execute command from args
 *@args: command arguments
 *
 *Return: status (An integer)
 */
int exec_cmd(char **args)
{
	int status = 0;
	char *cmd = NULL;
	int err_code = 0;

	/*builtin */
	if (_strcmp(*args, "exit") == 0)
		_exit_(args);

	if (_strcmp(*args, "env") == 0)
		_printenv();
	else
	{
		cmd = *args;
		*args = locate(*args);
		if (*args == NULL)
			dprintf(STDERR_FILENO, "%s: No such file or directory.\n", cmd);
		else if (fork() == 0)
		{
			err_code = execve(*args, args, NULL);
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", cmd);
			free(cmd);
			exit(err_code);
		}
		else
			wait(&status);
	}

	return (status);
}
