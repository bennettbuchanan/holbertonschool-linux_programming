#include "holberton.h"

int build_list(DIR *dir)
{
	struct dirent *read;
	List *list;
	
	list = NULL;
	while ((read = readdir(dir)) != NULL)
        {
 		/* printf("%s\n", read->d_name); */			
       		sort_dir(&list, read->d_name);
	}
	print_list(list);
	free_list(list);
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
		build_list(dir);
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
