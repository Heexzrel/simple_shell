#include "shell.h"

/**
 * _strcpy - Copy source string to destination
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the copied string
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * _strcat - Concatenate two strings
 * @dest: First string
 * @src: Second string
 * Return: Pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
    char *s = dest;

    while (*dest != '\0')
    {
        dest++;
    }

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return (s);
}

/**
 * _strchr - Locate character in a string
 * @s: String to search in
 * @c: Character to search for
 * Return: Pointer to the first occurrence of the character in the string
 */
char *_strchr(char *s, char c)
{
    do
    {
        if (*s == c)
        {
            break;
        }
    } while (*s++);

    return (s);
}

/**
 * _strncmp - Compare a specified number of characters of two strings
 * @s1: First string
 * @s2: Second string
 * @n: Number of characters to compare
 * Return: 0 if the strings match, otherwise 1
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    if (s1 == NULL)
        return -1;

    for (i = 0; i < n && s2[i]; i++)
    {
        if (s1[i] != s2[i])
        {
            return 1;
        }
    }
    return (0);
}

/**
 * _strdup - Duplicate a string
 * @str: String to duplicate
 * Return: Pointer to the duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
    size_t len, i;
    char *str2;

    len = _strlen(str);
    str2 = malloc(sizeof(char) * (len + 1));
    if (!str2)
    {
        return (NULL);
    }

    for (i = 0; i <= len; i++)
    {
        str2[i] = str[i];
    }

    return (str2);
}
