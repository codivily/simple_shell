#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

/**
 *_exit_ - exit with status
 * @args: Arguments array
 *Return: void
 */
void _exit_(char **args)
{
	int status = 0;
	size_t i = 0;

	while (args[i++])
	;

	if (i > 3)
		dprintf(STDERR_FILENO, "exit: too many arguments\n");
	else if (args[1] && !_is_numeric(args[1]))
		dprintf(STDERR_FILENO, "exit: %s: numeric argument required\n", args[1]);
	else if (_is_numeric(args[1]))
		status = _atoi(args[1]);

	free(args);

	exit(status);

}

