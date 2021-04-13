#include "shell.h"

/**
 *handle_commands - from arguments got from getline
 *@args: datastructure of type Args
 *
 *Return: void
 */

void handle_commands(Args *args)
{
	pid_t child_pid;
	int wStatus;
	char *path;
	void (*built_in_func)(Args *args);

	path = handle_path(args);
	built_in_func = get_command_opts(args->argv[0]);

	if (built_in_func != NULL)
	{
		single_free(path);
		built_in_func(args);

	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
			perror(*(args->prgm_name));
		if (child_pid == 0)
		{
			if (path)
			{
				if (execve(path, args->argv, NULL) == -1)
					perror(*(args->prgm_name));
			}
			else
			{
				if (execve(args->argv[0], args->argv, NULL) == -1)
					perror(*(args->prgm_name));
			}
		}
		else
			wait(&wStatus);
		single_free(path);
	}
	double_free(args->argv);
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
