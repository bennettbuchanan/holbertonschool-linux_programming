#include "holberton.h"

void print_str(char *str)
{
        int i;

        for(i = 0; str[i] != '\0'; i++)
        {
                print_char(str[i]);
        }
}
