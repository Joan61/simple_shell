#include "holberton.h"

/**
 *strlen_tokens - gets the length of string excluding spaces.
 *@*s: character pointer to the string.
 *
 *Return: length of a string when successful.
 */

int strlen_token(char *s)
{
	int length = 0, i;

	for(i = 0; s[i] != '\0'; i++)
	{
		if(s[i] == ' ')
			continue;
		length++;
	}
	return (length);
}


/**
 *get_args_length - gets the number of words in a sentence
 *using space as a delimeter.
 *
 *@*s: character pointer points to a string
 *Return: counts arguments in the string
 */

int get_args_length(char *s)
{
	int count = 0;
	char *newstring = s;
	char *token;

	token = strtok(newstring, ' ');
	while(token)
	{
		count++;
		token = strtok(NULL, " ");
	}

	return (count);
}

