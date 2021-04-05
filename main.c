#include "holberton.h"

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: arguments vectors
 * Return: (0) Success
 */

int main(int argc, char **argv)
{
	int status;

	status = isatty(STDIN_FILENO);
	loop(&status, argv);

	return (0);
}