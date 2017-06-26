#include "holberton.h"

/**
 * str_len - Get the length of the given string.
 * @str: The string to find the length of.
 *
 * Return: The length of the string.
 */
int str_len(char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * str_copy - Copy the given string into a new destination.
 * @src: The string to copy.
 *
 * Return: The copied string.
 */
char *str_copy(char *src)
{
	int len;
	char *dest;
	int i;

	len = str_len(src) + 1;
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
