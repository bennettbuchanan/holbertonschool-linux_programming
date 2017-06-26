#include <stdlib.h>
#include "holberton.h"

/** 
 * free_list - Free the given linked list.
 * @list: The list to free.
 *
 * Return: void.
 */
void free_list(List *list) 
{
	List *tmp;

	while(list != NULL) {
		tmp=list->next;
		free(list->str);
		free(list);
		list = tmp;
	}
}
