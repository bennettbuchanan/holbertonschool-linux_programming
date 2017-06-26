#include "holberton.h"

/**
 * print_list - Print the formatted output of the ls program.
 * @list: The linked list to print each node's string.
 *
 * Return: void.
 */
void print_list(List *list)
{
	while (list != NULL)
	{
		if (list->str[0] != '.')
		{
			print_str(list->str);
			print_char(' ');
			print_char(' ');
		}
		list = list->next;
	}
	print_char('\n');
}
