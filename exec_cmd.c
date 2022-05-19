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
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", shell_path);
		else if (fork() == 0)
		{
			err_code = execve(*args, args, environ);
			dprintf(STDERR_FILENO, "%s: No such file or directory\n", shell_path);
			free(cmd);
			exit(err_code);
		}
		else
			wait(&status);
	}

	return (status);
}

