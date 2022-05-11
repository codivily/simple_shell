#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>

int _putchar(char c);
void _puts(char *str);
char *prompt(const char *msg);
char **to_args(char *str);

#endif
