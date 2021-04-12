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
	void (*f)(Args *args);

	path = handle_path(args);
	f = get_command_opts(args->argv[0]);

	if (path != NULL)
	{
		f(args);
	}
	else if (path != NULL)
	{
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
			wait(&wStatus);
		}
	}
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
		if (strcmp(command, cmd_opts[i].cmd) == 0)
			return (cmd_opts[i].f);
		i++;
	}
	return (NULL);
}
