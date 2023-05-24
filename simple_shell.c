#include "shell.h"

/**
 * main - Entry point of the Simple Shell (Hsh)
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: Exit status
 */

char **parse_cmd(char *cmd);

int main(__attribute__((unused)) int argc, char **argv)
{
    char *input, **cmd;
    int counter = 0, statue = 1, st = 0;

    if (argv[1] != NULL)
        read_file(argv[1], argv);
    signal(SIGINT, signal_to_handel);
    while (statue)
    {
        counter++;
        if (isatty(STDIN_FILENO))
            prompt();
        input = _getline();
        if (input[0] == '\0')
        {
            continue;
        }
        history(input);
        cmd = parse_cmd(input);
        if (cmd == NULL) {
            free(input);
            continue;
        }
        if (_strcmp(cmd[0], "exit") == 0)
        {
            exit_bul(cmd, input, argv, counter);
        }
        else if (check_builtin(cmd) == 0)
        {
            st = handle_builtin(cmd, st);
            free_all(cmd, input);
            continue;
        }
        else
        {
            st = check_cmd(cmd, input, counter, argv);
        }
        free_all(cmd, input);
    }
    return (statue);
}

/**
 * parse_cmd - Parse the command line into individual arguments
 */
char **parse_cmd(char *cmd)
{
    char **args = malloc(sizeof(char *) * MAX_ARGS);
    if (args == NULL) {
        return (NULL);
    }

    char *token;
    int arg_count = 0;

    token = strtok(cmd, " ");
    while (token != NULL && arg_count < MAX_ARGS - 1) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    return (args);
}


/**
 * check_builtin - Check if the command is a built-in command
 * @cmd: Command to check
 * Return: 0 on success, -1 on failure
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;

	if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}

	return (-1);
}

/**
 * creat_envi - Create an array of environment variables
 * @envi: Array of environment variables
 * Return: Void
 */
void creat_envi(char **envi)
{
	int i;

	/* Copy environment variables into the array*/
	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);

	envi[i] = NULL;
}
