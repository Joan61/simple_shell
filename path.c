#include "shell.h"

/**
 * file_in_path - checks for program existence is a provided path
 * @program_path: string pointer to path
 * Return: (0) if file found and (1) if not
 */

int file_in_path(char *program_path)
{
	struct stat st;

	if (stat(program_path, &st) == 0)
		return (0);
	return (1);
}

/**
 * is_path - checks if supplied argument is a path.
 * detects using '/' as delimeter
 * @s: pointer to string to check
 * Return: (0) if the string argument supplied is path and (1) if not
 */

int is_path(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '/')
			return (0);
		i++;
	}
	return (1);
}

/**
 * handle_path - handling of path
 * @args: pointer to data structure Args
 * Return: new path for the command argument else NULL if a path couldn't be
 * generated
 */

char  *handle_path(Args *args)
{
	char *token, *generated_path, *full_path_value;

	if (args == NULL)
		return (NULL);

	if (is_path(args->argv[0]) == 0)
	{
		if (file_in_path(args->argv[0]) == 0)
			return (_strdup(args->argv[0]));
		return (NULL);
	}

	full_path_value = _get_env_value("PATH", args);
	token = strtok(full_path_value, ":");
	while (token)
	{
		generated_path = concat_create_path_string(token, args->argv[0]);
		if (!generated_path)
			return (NULL);
		if (file_in_path(generated_path) == 0)
		{
			single_free(full_path_value);
			return (generated_path);
		}
		token = strtok(NULL, ":");
		single_free(generated_path);
	}

	single_free(full_path_value);

	return (NULL);
}

/**
 * concat_create_path_string - creates a new string path from string arguments
 * @s1: first string
 * @s2: second string
 * Return: pointer to the new generated string
 */

char *concat_create_path_string(char *s1, char *s2)
{
	char *new_string;

	if (!s1 || !s2)
		return (NULL);

	new_string = malloc(sizeof(char) * (_str_length(s1) + _str_length(s2) + 2));

	if (!new_string)
		return (NULL);

	new_string[0] = '\0';

	_strcat(new_string, s1);
	_strcat(new_string, "/");
	_strcat(new_string, s2);

	return (new_string);
}
