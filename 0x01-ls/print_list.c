#include "holberton.h"

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
