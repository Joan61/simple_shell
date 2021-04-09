#include "shell.h"

/**
 *@handle_argv - creates an array of strings generated from getline
 *
 *Return: array of strings.
 */

char **handle_argv(char *line)
{
	char *token;
	char *line_duplicate = _strdup(line);
	char **argv;
	int argc = get_args_length(line_duplicate);
	int i = 0;

	argv = malloc(sizeof(char *) * (argc + 1));

	token = strtok(line, " '\n''\t'");
while (token)
{
argv[i] = malloc(sizeof(char) * (_str_length(line) + 1));
argv[i] = token;
token = strtok(NULL, " '\n''\t'");
	i++;
}

free(line_duplicate);

return (argv);
}
