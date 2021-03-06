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

		if (*status)
			print_stdout("$ ");

		lines_read = getline(&line, &line_count, stdin);

		if (lines_read == -1)
		{
			single_free(line);
			print_stdout("\n");
			fflush(stdout);
			exit(EXIT_SUCCESS);
		}
		handle_argv(args, line);

		if (args->argc == 0)
		{
			single_free(line);
			double_free(args->argv);
			continue;
		}

		single_free(line);
		handle_commands(args);
		fflush(stdout);
	} while (*status && (lines_read != -1));
}
