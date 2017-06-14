#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

void open_and_check_dir(char *path);
int lstat(const char *path, struct stat *buf);
char *strcat(char *dest, const char *src);
char *strcpy(char *dest, const char *src);
void *malloc(size_t size);
void free(void *pointer);

int print_dir(char *path, DIR *dir)
{
	struct dirent *read;
        struct stat sb;
        char *cpy;
	
	while ((read = readdir(dir)) != NULL)
        {
                cpy = malloc(sizeof(path));
                strcpy(cpy, path);
                lstat(strcat(cpy, read->d_name), &sb);
                printf("%s %ld\n", read->d_name, (long) sb.st_size);
                free(cpy);
        }
	return (0);
}

void open_and_check_dir(char *path)
{
	DIR *dir;
	
	dir = opendir(path);
	if (errno == ENOENT)
	{
		printf("hls: cannot access %s: No such file or directory\n", 
			path);
	}
        else 
	{
		print_dir(path, dir);
        	closedir(dir);
	}
}

int main(int argc, char **argv) 
{
	char *path;
	
	if (argc == 1)
	{
		path = "./";
	}
	else
	{
		path = argv[1];
	}
        open_and_check_dir(path);
	return (0);
}
