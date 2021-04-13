#include "shell.h"

/**
 * double_free - frees memory allocated to a pointer to string
 * of pointers, ie a two dimesion array
 * @args: an array of strings
 * Return: nothing
 */

void double_free(char **args)
{
	int i;

	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
		{
			if (args[i])
				free(args[i]);
		}
		free(args);
	}
}

/**
 * single_free - frees memory allocated to a certain memory location
 * @arg: address of the location
 * Return: nothing
 */

void single_free(char *arg)
{
	if (arg)
		free(arg);
}
