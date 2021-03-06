#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/**
 *struct args - contains all argument variables for program
 *@argv: array of strings received by program thru stdin
 *@env: environment variables from main function.
 *@argc: arguments count of @argv
 *@prgm_name: name of program, usually index 0 of main function.
 *argv argument
 */

typedef struct args
{
	char **argv;
	char **env;
	char **prgm_name;
	int argc;
} Args;

/**
 * struct opts - contains commands for our program
 * @cmd: string pointer to string command
 * @f: pointer to function
 */

typedef struct opts
{
	char *cmd;
	void (*f)(Args *args);
} Opts;

int _str_length(char *s);
char *_strdup(char *str);
int get_args_length(char *s);
char **handle_argv(Args *args, char *line);
char *_getenv(char *name, Args *args);
char *_strcat(char *dest, char *src);
char *concat_create_path_string(char *s1, char *s2);
char *_get_env_value(char *env_var, Args *args);
int file_in_path(char *program_path);
int is_path(char *s);
char *handle_path(Args *args);
void handle_commands(Args *args);
void loop(int *status, Args *args);
void double_free(char **args);
void single_free(char *arg);
int _strcmp(char *s1, char *s2);
void too_many_args_err(Args *args);
int isNumericChar(char x);
int _atoi(char *s);
void change_directory(Args *args);

void print_stdout(char *s);
void print_stderr(char *s);
void create_child(Args *args, char *path);
void construct_error(Args *args);
void _printenv(Args *args);
void program_exit(Args *args);
void (*get_command_opts(char *command))(Args *args);

#endif
