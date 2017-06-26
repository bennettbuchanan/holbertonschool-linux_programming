#include "holberton.h"

/**
 * print_str - Print the given string.
 * @str: The string to print.
 *
 * Return: void.
 */
void print_str(char *str)
{
	int i;

	for(i = 0; str[i] != '\0'; i++)
	{
		print_char(str[i]);
	}
}
