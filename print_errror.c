#include "shell.h"

/**
 * _prerror - Print Custom Error Message
 * @argv: Array of program arguments
 * @c: Error count
 * @cmd: Array of command arguments
 * Return: void
 */
void _prerror(char **argv, int c, char **cmd)
{
	char *errorCount = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(errorCount);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Illegal number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");

	free(errorCount);
}
