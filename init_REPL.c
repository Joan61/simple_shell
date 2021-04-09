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
		printf("alex@linux~$ ");
		lines_read = getline(&line, &line_count, stdin);
		if (lines_read != -1)
		{
			args->argv = handle_argv(line);
			handle_commands(args);
		}
		else
		{
			printf("\n");
		}
	} while (*status && (lines_read != -1));
	free(line);
	freeGrid(args->argv);
}
