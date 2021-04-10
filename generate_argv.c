#include "shell.h"

/**
 * handle_argv - creates an array of strings generated from getline
 * @args: Args data structure
 * @line: pointer to a string got  from the stdin
 * Return: array of strings.
 */

char **handle_argv(Args *args, char *line)
{
	char *token, *line_duplicate;
	int argc, i = 0, j;

	if (!line)
		return (NULL);
	line_duplicate = _strdup(line);
	argc = get_args_length(line_duplicate);

	args->argv = malloc(sizeof(char *) * (argc + 1));

	if (!args->argv)
		return (NULL);

	token = strtok(line, " '\n''\t'");
	while (token)
	{
		args->argv[i] = malloc(sizeof(char) * (_str_length(token) + 1));

		for (j = 0; token[j] != '\0'; j++)
			args->argv[i][j] = token[j];
		args->argv[i][j] = '\0';
		token = strtok(NULL, " '\n''\t'");
		i++;
	}
	args->argv[i] = NULL;

	free(line_duplicate);
	return (args->argv);
}
