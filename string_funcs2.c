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
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((int)(unsigned char)(*s1) - (int)(unsigned char)(*s2));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - prints string to the stdout
 * @s: string to be printed
 * Return: nothing
 */

void _print(char *s)
{
	int i = 0;

	if (s)
	{
		while (s[i])
		{
			_putchar(s[i]);
			i++;
		}
	}
}
