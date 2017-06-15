#include "holberton.h"

int is_cap(char c)
{
        if (c > 64 && c < 91)
        {
                return (0);
        }
        return (1);
}

char normalize_char(char c)
{
        if (is_cap(c) == 0)
        {
                return (c + 32);
        }
        return (c);
}

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

void insert_in_list(List *node, List **list)
{
	List *tmp = *list;
	List *tmp1 = *list;
	int i;
	
	for (i = 0; tmp->next != NULL && 
	(is_greater(node->str, tmp->str) == 0); i++)
	{
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

int sort_dir(List **list, char *fn)
{	
	List *node;
		
	if ((node = allocate_node(fn)) == NULL)
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
