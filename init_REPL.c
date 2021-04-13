#include "shell.h"

/**
 * loop - initializes a read print evaluate loop for interactive mode
 * @status: int to determine if current file descriptor is a terminal
 * or not
 * @args: Args data structure
 * Return: nothing
 */

void loop(int *status, Args *args)
{
	char *line;
	size_t line_count;
	ssize_t lines_read;

	do {
		line = NULL;
		line_count = 0;

		_print("#cisfun$ ");
		lines_read = getline(&line, &line_count, stdin);

		if (lines_read == -1)
		{
			single_free(line);
			break;
		}

		handle_argv(args, line);
		single_free(line);
		handle_commands(args);
	} while (*status && (lines_read != -1));
}
