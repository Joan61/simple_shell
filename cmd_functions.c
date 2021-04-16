#include "shell.h"

/**
 * program_exit - handles exiting of the program
 * @args: data structure of Args
 * Return: nothing
 */

void program_exit(Args *args)
{
	int status;

	if (args->argc > 2)
	{
		too_many_args_err(args);
	}
	else if (args->argv[1])
	{
		status = _atoi(args->argv[1]);
		double_free(args->argv);
		fflush(stdout);
		exit(status);
	}
	else
	{
		double_free(args->argv);
		fflush(stdout);
		exit(EXIT_SUCCESS);
	}
}

/**
 * too_many_args_err - prints too many arguments to stderr
 * @args: data structure of args
 * Return: nothing
 */

void too_many_args_err(Args *args)
{
	print_stderr(*(args->prgm_name));
	print_stderr(": ");
	print_stderr(args->argv[0]);
	print_stderr(": too many arguments\n");
}

/**
 * _printenv - prints the current environment
 * @args: data structure of Args
 * Return: nothing
 */

void _printenv(Args *args)
{
	char **envp = args->env;

	while (*envp)
	{
		print_stdout(*envp);
		print_stdout("\n");
		envp++;
	}
}

/**
 * change_directory - handles changing of a directory to another
 * @args: data structure of args
 * Return: nothing
 */

void change_directory(Args *args)
{
	char *path;

	if (args->argc == 1)
	{
		path = _get_env_value("HOME", args);
		if (chdir(path) == -1)
		{
			perror(*(args->prgm_name));
		}
		single_free(path);
	}
	else if (args->argc > 2)
	{
		too_many_args_err(args);
	}
	else
	{
		if (chdir(args->argv[1]) == -1)
		{
			perror(*(args->prgm_name));
		}
	}
}
