#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

int _islower(int c)
{

}

int _isalpha(int c)
{

}

int _abs(int n)
{

}

int _isupper(int c)
{

}

int _isdigit(int c)
{

}

/**
 * _strlen - Get the length of the given string
 *
 * @s Pointer to the string to find the length of
 * 
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void _puts(char *s)
{

}

char *_strcpy(char *dest, char *src)
{

}

int _atoi(char *s)
{

}

char *_strcat(char *dest, char *src)
{

}

char *_strncat(char *dest, char *src, int n)
{

}

char *_strncpy(char *dest, char *src, int n)
{

}

int _strcmp(char *s1, char *s2)
{

}

int _strncmp(char *s1, char *s2, unsigned int n)
{

}

char *_memset(char *s, char b, unsigned int n)
{

}

char *_memcpy(char *dest, char *src, unsigned int n)
{

}

char *_strchr(char *s, char c)
{

}

unsigned int _strspn(char *s, char *accept)
{

}

char *_strpbrk(char *s, char *accept)
{

}

char *_strstr(char *haystack, char *needle)
{

}
