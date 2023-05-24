#include "shell.h"

/**
 * _strcmp - Compare two strings
 * @s1: First string
 * @s2: Second string
 * Return: 0 if the strings are identical, otherwise the difference
 */
int _strcmp(char *s1, char *s2)
{
    int cmp = 0, i, len1, len2;
    len1 = _strlen(s1);
    len2 = _strlen(s2);

    if (s1 == NULL || s2 == NULL)
        return 1; /* Indicates a difference if either string is NULL */
    if (len1 != len2)
        return 1; /* Indicates a difference if the lengths are different*/
    for (i = 0; s1[i]; i++)
    {
        if (s1[i] != s2[i])
        {
            cmp = s1[i] - s2[i];
            break;
        }
        else
            continue;
    }
    return cmp; /* Returns the difference between the first differing characters*/
}

/**
 * _isalpha - Check if it is Alphabtic
 *@c: Character
 * Return:Return  1 If True or  0 If Not
 */
int _isalpha(int c)
{
	if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _itoa - Convert Integer To Character
 * @n: Int To Convert
 * Return: Char Pointer
 */
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}
/**
 *  array_rev - Reverse Array
 * @arr:Array To Reverse
 * @len:Length Of Array
 * Return: Void
 */
void array_rev(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
/**
 * intlen - Determines length Of Int
 * @num: Given Int
 * Return: Length Of Int
 */
int intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
