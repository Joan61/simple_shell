#include "shell.h"

/**
 * freeGrid - frees memory allocated to a pointer to string
 * of pointers, ie a two dimesion array
 * @args: an array of strings
 * Return: nothing
 */

void freeGrid(char **args)
{
	int i;

	for (i = 0; args[i] != '\0'; i++)
		free(args[i]);
	free(args);
}
