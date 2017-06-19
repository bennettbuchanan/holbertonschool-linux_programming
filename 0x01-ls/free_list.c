#include <stdlib.h>
#include "holberton.h"

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
