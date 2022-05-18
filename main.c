#include <stdlib.h>
#include <sys/wait.h>

/**
 *main - Entry point
 *@argc: An integer
 *@argv: List of command line arguments
 *
 *Return: An integer
 */
int main(int argc, char **argv)
{
	char *cmd_str = NULL;
	char **args = NULL;
	int exit_code = 0;
	int status = 0;

	/*an infinite loop */
	while (1)
	{
		/*command line args support */
		if (argc > 1)
			args = argv + 1;
		else
		{
			/*prompt the user  to enter command */
			cmd_str = prompt("#cisfun$ ");
			/*command args */
			args = to_args(cmd_str);
		}

		status = exec_cmd(args);
		free(cmd_str);
		cmd_str = NULL;
		if (argc > 1)
			exit(status);
	}

	return (0);
}
