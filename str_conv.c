#include "shell.h"

/**
 * long_to_string - Converts a number to a string.
 * @number: Number to be converted into a string.
 * @string: Buffer to store the number as a string.
 * @base: Base to convert the number.
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, isNegative = 0;
	long quotient = number;
	char letters[] = {"0123456789abcdef"};

	if (quotient == 0)
		string[index++] = '0';

	if (string[0] == '-')
		isNegative = 1;

	while (quotient)
	{
		if (quotient < 0)
			string[index++] = letters[-(quotient % base)];
		else
			string[index++] = letters[quotient % base];
		quotient /= base;
	}

	if (isNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - Converts a string to an integer.
 *
 * @s: Pointer to the source string.
 * Return: Integer value of the string or 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;

	/* Step 1: Analyze the sign */
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	/* Step 2: Extract the number */
	while ('0' <= *s && *s <= '9' && *s != '\0')
	{
		number = (number * 10) + (*s - '0');
		s++;
	}

	return (number * sign);
}

/**
 * count_characters - Counts the occurrences of a character in a string.
 *
 * @string: Pointer to the source string.
 * @character: String with characters to be counted.
 * Return: Integer count of the characters or 0.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}

	return (counter);
}
