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

/**
 * isNumericChar - determines numeric character or not
 * @x: character to be tested
 * Return: 0 (False if not numeric)
 * 1 (True if is numeric)
 */

int isNumericChar(char x)
{
	return ((x >= '0' && x <= '9') ? 1 : 0);
}

/**
 * _atoi - converts string to integer
 * @s: string to convert to integer
 * Return: converted integer string
 */

int _atoi(char *s)
{
	int result = 0, sign = 1, i = 0;

	if (*s == '\0')
		return (0);

	for (; s[i] != '\0'; i++)
	{
		if (!isNumericChar(s[i]))
		{
			if (s[i] == '-')
				sign *= (-1);
			continue;
		}

		result = ((result * 10) + (s[i] - '0'));

		if (s[i + 1] == ' ')
			break;
	}
	return (sign * result);
}
