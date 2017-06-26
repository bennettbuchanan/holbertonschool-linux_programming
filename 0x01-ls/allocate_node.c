#include "holberton.h"

/**
 * allocate_node - allocate memory for a node in the list.
 * @str: The str to assign the List struct str value of the node.
 *
 * Return: Pointer to the allocated node, NULL if malloc fails.
 */
List *allocate_node(char *str)
{
	List *node;

	node = malloc(sizeof(List));
	if (node == NULL)
	{
		return (NULL);
	}
	node->str = str_copy(str);
	return (node);
}
