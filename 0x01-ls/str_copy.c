#include "holberton.h"

int str_len(char *str)
{
	int len = 0;
	
	while(str[len] != '\0')
	{
		len++;
	}
	return len;
}

char *str_copy(char *src)
{
	int len;
	char *dest;
	int i;
	
	len = str_len(src) + 1;	
	if ((dest = malloc(sizeof(char) * len)) == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
