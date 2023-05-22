#include "shell.h"

/**
 * tokenize - This function separates a string into different parts using a specified delimiter.
 * @data: A pointer to the program's data.
 * Return: An array of the different parts of the string.
 */
void tokenize(data_of_program *data)
{
	char *delimiter = " \t"; /* Delimiter used to separate the string*/
	int i, j, counter = 2, length;

	length = str_length(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	/* Counting the number of tokens in the input line*/
	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delimiter[j]; j++)
		{
			if (data->input_line[i] == delimiter[j])
				counter++;
		}
	}

	/* Allocating memory for the tokens array*/
	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}

	i = 0;
	data->tokens[i] = str_duplicate(_strtok(data->input_line, delimiter)); /* Get the first token*/
	data->command_name = str_duplicate(data->tokens[0]); /* Set the command name to the first token*/

	/* Iterate over the remaining tokens and storing them in the tokens array*/
	while (data->tokens[i++])
	{
		data->tokens[i] = str_duplicate(_strtok(NULL, delimiter));
	}
}
