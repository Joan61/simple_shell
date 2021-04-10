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
	char *line = NULL;
	size_t line_count = 0;
	ssize_t lines_read;

	do {
		printf("#cisfun$ ");
		lines_read = getline(&line, &line_count, stdin);
		if (lines_read == -1)
		{
			printf("\n");
			break;
		}

		handle_argv(args, line);
		if (args->argv)
			handle_commands(args);
	} while (*status && (*line != EOF));
}
