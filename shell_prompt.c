#include "shell.h"

/**
 * prompt - Display the shell prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}

/**
 * print_error - Display an error message based on the command and shell loop count
 * @input: User input
 * @counter: Shell loop count
 * @argv: Program name
 * Return: Void
 */
void print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": command not found\n");
}

