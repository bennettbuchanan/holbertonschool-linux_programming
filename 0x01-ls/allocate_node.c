#include "holberton.h"

List *allocate_node(char *str)
{
	List *node;

	if ((node = malloc(sizeof(List))) == NULL)
	{
		return (NULL);
	}
	node->str = str_copy(str);
	return (node);
}
