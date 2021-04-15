#include "shell.h"

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vectors
 *@env:  contains all environmental variables
 * Return: (0) Success
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	int status;
	Args arguments;

	arguments.prgm_name = argv;
	arguments.env = env;

	status = isatty(STDIN_FILENO);
	loop(&status, &arguments);

	return (0);
}
