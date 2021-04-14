#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string to copare
 * @s2: second string to compare
 * Return: 0 (if both stirngs are equal), negative integer if @s1 is
 * less than @s2 and positive integer if @s1 is greater than @s2
 */

int _strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);

	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)(unsigned char)(*s1) - (int)(unsigned char)(*s2));
}

/**
 * print_stdout - prints string to the stdout
 * @s: string to be printed
 * Return: nothing
 */

void print_stdout(char *s)
{
	write(STDOUT_FILENO, s, _str_length(s));
}

/**
 * print_stderr - prints string to the stderr
 * @s: string to be printed
 * Return: nothing
 */

void print_stderr(char *s)
{
	write(STDERR_FILENO, s, _str_length(s));
}
