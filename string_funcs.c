#include "shell.h"

/**
 * _str_length - gets the length of the string
 * @s: pointer to a string
 * Return: length of the string
 */

int _str_length(char *s)
{
	int i = 0;

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

	if (str == 0)
		return (0);

	newStr = malloc((_str_length(str) + 1) * sizeof(char));

	if (newStr == 0)
		return (0);

	for (i = 0; i < _str_length(str); i++)
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
	int length = 0, i;

	for (i = 0; dest[i] != '\0'; i++)
		length++;

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
	char *newstring = s;
	char *token;

	token = strtok(newstring, " '\n''\t'");
	while (token)
	{
		count++;
		token = strtok(NULL, " '\n''\t'");
	}

	return (count);
}
