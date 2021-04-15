#include "shell.h"

/**
 * _str_length - gets the length of the string
 * @s: pointer to a string
 * Return: length of the string
 */

int _str_length(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (s[i] != '\0')
		i++;

	return (i);
}

/**
 * _strdup - duplicates a sting
 * @str: pointer to string to duplicate
 * Return: pointer to memory location of the duplicated string
 */

char *_strdup(char *str)
{
	char *newStr;
	int i = 0;

	if (!str)
		return (NULL);

	newStr = malloc((_str_length(str) + 1) * sizeof(char));

	if (!newStr)
		return (NULL);

	for (i = 0; i < (_str_length(str) + 1); i++)
		newStr[i] = str[i];

	return (newStr);
}

/**
 * _strcat - concatenates two strings
 * @dest: location to concatenate string
 * @src: string to concatenate to dest
 * Return: resulting string after concatenation
 */

char *_strcat(char *dest, char *src)
{
	int length = 0, i = 0;

	if (!dest || !src)
		return (NULL);

	length = _str_length(dest);

	for (i = 0 ; src[i] != '\0' ; i++)
		dest[length + i] = src[i];

	dest[length + i] = '\0';

	return (dest);
}

/**
 * get_args_length - counts the number of words found in a string
 * using space, newline and tab as delimeters
 * @s: string to count words
 * Return: number of words
 */

int get_args_length(char *s)
{
	int count = 0;
	char *token;

	if (!s)
		return (0);

	token = strtok(s, " '\r''\n''\t'");

	while (token)
	{
		count++;
		token = strtok(NULL, " '\r''\n''\t'");
	}

	return (count);
}
