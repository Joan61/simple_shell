#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int strlen_tokens(char *s);
int get_args_length(char *s);
char  **handle_argv(char *line);
void handle_commands(char **argv, char **main_argv);
void loop(int *status, char **av);

#endif
