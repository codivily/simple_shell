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
#include <signal.h>

int _putchar(char c);
int file_exists(const char *filename);
void _puts(char *str);
char *prompt(const char *msg);
char **to_args(char *str);
char *_strdup(const char *str);
char *_getenv(const char *name);
char *locate(const char *name);
char *join_paths(char separator, const char *p1, const char *p2);

#endif
