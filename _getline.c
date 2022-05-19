#include "main.h"
#include "unistd.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *_getline - get the next line from a file
 *@fd: file descriptor
 *
 *Return: A string
 */
char *_getline(int fd)
{
	static char chk[32], *p_chk;
	static ssize_t n_read;
	size_t max_len = 0, len = 0, i = 0;
	char *line = NULL;

	line = malloc(sizeof(*line) * (max_len + 1));
	while (1)
	{
		for (i = 0; i < n_read && p_chk[i] != '\n'; i++)
		;
		_memcpy(line + len, p_chk, i);
		len += i;
		if (i < n_read)
		{
			n_read -= (i + 1);
			p_chk += (i + 1);
			break;
		}

		p_chk = chk;
		n_read = read(fd, chk, sizeof(chk));
		if (n_read <= 0)
			break;
		if (n_read > max_len - len)
		{
			max_len += sizeof(chk);
			line = _realloc(line, (max_len + 1));
		}
	}

	line[len] = '\0';
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
	}

	return (line);
}
