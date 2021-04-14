#include "shell.h"

/**
 *handle_commands - from arguments got from getline
 *@args: datastructure of type Args
 *
 *Return: void
 */

void handle_commands(Args *args)
{
	char *path;
	void (*built_in_func)(Args *args);

	path = handle_path(args);
	built_in_func = get_command_opts(args->argv[0]);

	if (built_in_func != NULL)
	{
		single_free(path);
		built_in_func(args);

	}
	else if (path != NULL)
	{
		create_child(args, path);
		single_free(path);
	}
	else
	{
		construct_error(args);
	}

	double_free(args->argv);
}

/**
 * create_child - creates a child process identical to parent process
 * @args: data structure of Args
 * @path: pointer to a string to generated path
 * Return: nothing
 */

void create_child(Args *args, char *path)
{
	pid_t child_pid;
	int wStatus;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(*(args->prgm_name));
	}
	else if (child_pid == 0)
	{
		if (execve(path, args->argv, NULL) == -1)
			perror(*(args->prgm_name));
	}
	else
	{
		 waitpid(child_pid, &wStatus, 0);
	}
}

/**
 * construct_error - creates an error message to stderr
 * @args: data structure of Args
 * Return: nothing
 */

void construct_error(Args *args)
{
	print_stderr(*(args->prgm_name));
	print_stderr(": ");
	print_stderr(args->argv[0]);
	print_stderr(": command not found\n");
}

/**
 * get_command_opts - fetches command options for the program
 * @command: pointer to string command
 * Return: nothing
 */

void (*get_command_opts(char *command))(Args *args)
{
	int i = 0;
	Opts cmd_opts[] = {
		{"exit", program_exit},
		{"env", _printenv},
		{NULL, NULL}
	};

	while (cmd_opts[i].cmd != NULL)
	{
		if (_strcmp(command, cmd_opts[i].cmd) == 0)
			return (cmd_opts[i].f);
		i++;
	}
	return (NULL);
}
