#include "holberton.h"

/**
 * is_chap - Determines if the given character is a capital letter.
 * @c: The character.
 *
 * Return: 0 if capital, 1 otherwise.
 */
int is_cap(char c)
{
	if (c > 64 && c < 91)
	{
		return (0);
	}
	return (1);
}

/**
 * normalize_char - Make any character that is a capital, lowercase.
 * @char: The character to normalize.
 *
 * Return: The normalized character.
 */
char normalize_char(char c)
{
	if (is_cap(c) == 0)
	{
		return (c + 32);
	}
	return (c);
}

/**
 * is_greater - Determine if string1 is greater than string2 based on the
 * output of the ls program.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return: 0 if string1 is greater than string2, 1 otherwise.
 */
int is_greater(char *str1, char *str2)
{
	int i;

	for (i = 0; i <= str_len(str1) && i <= str_len(str2); i++)
	{
		if (normalize_char(str1[i]) > normalize_char(str2[i]))
		{
			return (0);
		}
		if (normalize_char(str1[i]) < normalize_char(str2[i]))
		{
			return (1);
		}
	}
	for (i = 0; i <= str_len(str1) && i <= str_len(str2); i++)
	{
		if (is_cap(str1[i]) == 0 && is_cap(str2[i]) == 1)
		{
			return (0);
		}
	}
	return (1);
}

/**
 * insert_in_list - Handle inserting a node in the linked list in the correct
 * order based on the result of comparing node strings.
 * @node: The node to insert.
 * @list: The linked list to insert into.
 *
 * Return: void.
 */
void insert_in_list(List *node, List **list)
{
	List *tmp = *list;
	List *tmp1 = *list;
	int i;

	for (i = 0; tmp->next != NULL; i++)
	{
		if (is_greater(node->str, tmp->str) == 1)
		{
			break;
		}
		tmp1 = tmp;
		tmp = tmp->next;
	}
	if (is_greater(tmp->str, node->str) == 0)
	{
		node->next = tmp;
		if (i > 0)
		{
			tmp1->next = node;
		}
		else
		{
			*list = node;
		}
	}
	else
	{
		node->next = tmp->next;
		tmp->next = node;
	}
}

/**
 * sort_dir - Handle building the sorted contents of a directory.
 * @list: The linked list.
 * @fn: The file name to sort.
 *
 * Return: 0 on success, 1 otherwise.
 */
int sort_dir(List **list, char *fn)
{
	List *node;

	node = allocate_node(fn);
	if (node == NULL)
	{
		return (1);
	}

	if (*list != NULL)
	{
		insert_in_list(node, list);
	}
	else
	{
		node->next = *list;
		*list = node;
	}
	return (0);
}
