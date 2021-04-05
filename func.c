#include "holberton.h"

/**
 *strlen_token - gets the length of string excluding spaces.
 *@s: character pointer to the string.
 *
 *Return: length of a string when successful.
 */

int strlen_token(char *s)
{
	int length = 0, i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			continue;
		length++;
	}
	return (length);
}


/**
 *get_args_length - gets the number of words in a sentence
 *using space as a delimeter.
 *
 *@s: character pointer points to a string
 *Return: counts arguments in the string
 */

int get_args_length(char *s)
{
	int count = 0;
	char *newstring = s;
	char *token;

	token = strtok(newstring, ' ');
	while (token)
	{
		count++;
		token = strtok(NULL, " ");
	}

	return (count);
}

/**
 * handle_argv - create and return an array of strings generated from getline
 * @line: pointer to a string
 *
 * Return: pointer to pointer pointing to strings
 */

char  **handle_argv(char *line)
{
	char *token;
	char *line_duplicate = strdup(line);
	char **argv;
	int argc = get_args_length(line_duplicate);
	int i = 0;

	argv = malloc(sizeof(char *) * argc * strlen_tokens(line));

	token = strtok(line, " ");
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	return (argv);
}

/**
 * handle_commands - handle commands from arguments got from getline
 * @argv: array of strings generated from getline
 * @main_argv: array of strings from main function
 * Return: nothing
 */

void handle_commands(char **argv, char **main_argv)
{
	pid_t child_pid;
	int wStatus;

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("Failed to fork process");
		exit(98);
	}

	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			printf("%s: No such file or directory\n", main_argv[0]);
			exit(99);
		}
	}
	else
	{
		wait(&wStatus);
	}
}

/**
 * loop - handle interactive mode and non interactive
 * @status: interactive or not interactive state integer pointer
 * @av: array of strings to main function argv
 * Return: nothing
 */

void loop(int *status, char **av)
{
	char *line = NULL;
	size_t line_count = 0;
	ssize_t lines_read;
	char **argv;

	do {
		printf("#cisfun$ ");
		lines_read = getline(&line, &line_count, stdin);
		line[lines_read - 1] = '\0';
		argv = handle_argv(line);
		handle_commands(argv, av);
	} while (*status && (lines_read != -1));
}
