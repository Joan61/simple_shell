#include "shell.h"

/**
 * _getenv - gets an environment variable depending on it's name
 * @name: name of the env variable
 * @args: data structure of type Args
 * Return: pointer to the environment variable location
 */

char *_getenv(char *name, Args *args)
{
	int i;
	char *token, *env_dup;

	for (i = 0; args->env[i] != '\0'; i++)
	{
		env_dup = _strdup(args->env[i]);
		token = strtok(env_dup, "=");
		if (_strcmp(token, name) == 0)
		{
			single_free(env_dup);
			break;
		}
		single_free(env_dup);
	}

	return (args->env[i]);
}

/**
 * _get_env_value - gets the value of a certain environment variable
 * @env_var: environment variable to get it's value
 * @args: data structure of type Args
 * Return: value of the environment variable
 */

char *_get_env_value(char *env_var, Args *args)
{
	char *tmp, i = 0;

	tmp = _getenv(env_var, args);
	while (*(tmp + i))
	{
		if (*(tmp + i) == '=')
			break;
		i++;
	}

	tmp = (tmp + (i + 1));
	return (_strdup(tmp));
}
