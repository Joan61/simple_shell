#include "shell.h"

/**
 * program_exit - handles exiting of the program
 * @args: data structure of Args
 * Return: nothing
 */

void program_exit(Args *args)
{
	double_free(args->argv);
	fflush(stdout);
	exit(EXIT_SUCCESS);
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
