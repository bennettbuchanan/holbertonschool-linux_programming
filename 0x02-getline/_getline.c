#include "_getline.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getline - Return a line of the given file descriptor.
 * @fd: The file descriptor to retrieve a line from.
 *
 * Return: The line if not EOF, NULL otherwise.
 */
char *_getline(const int fd)
{
	char c;
	char *line;
	char *tmp;
	int i;
	int buf_size = BUFFER_SIZE;

	if (fd < 0)
	{
		return (NULL);
	}
	line = malloc(buf_size * sizeof(char));
	for (i = 0; read(fd, &c, READ_SIZE) != 0; i++)
	{
		if (c == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		/* If the line is greater than buf_size */
		if (i == buf_size)
		{
			buf_size += BUFFER_SIZE;
			tmp = line;
			line = malloc(buf_size * sizeof(char));
			memcpy(line, tmp, i);
			free(tmp);
		}
		line[i] = c;
	}
	free(line);
	return (NULL);
}
