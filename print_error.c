#include <unistd.h>
#include "main.h"

/**
 * print_error - print on error on the stderr
 * @cmd: A string
 * @msg: A string
 *
 * Return: void
 */
void print_error(char *cmd, char *msg)
{
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));
}
