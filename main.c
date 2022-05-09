#include "main.h"

/**
 * main - Entry point
 * @argc: An integer
 * @argv: List of command line arguments
 *
 * Return: An integer
 */
int main(int argc, char **argv)
{
	char *cmd = NULL;
	char *msg = "#cisfun$ ";
	char *cmd_args[2] = {NULL, NULL};
	int ok = 0;

	/* an infinite loop */
	while (1)
	{
		/* read the command from the user */
		cmd = prompt(msg);

		/* command args */
		cmd_args[0] = cmd;

		/* execute command */	
		ok = execve(cmd, cmd_args, NULL);
		
		/* print an error is command not found */
		if (ok == -1)
			perror("Command not found");

		/* release malloced memory from prompt function call */
		free(cmd);
	}


	return (0);
}
