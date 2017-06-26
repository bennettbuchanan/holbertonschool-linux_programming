#include <unistd.h>

/**
 * print_char - Print the given character using the write function.
 * @c: The character to print.
 *
 * Return: The returned value of the write function.
 */
int print_char(char c)
{
	return (write(1, &c, 1));
}
