#include "holberton.h"

int build_list(DIR *dir)
{
	struct dirent *read;
	List *list;
	
	list = NULL;
	while ((read = readdir(dir)) != NULL)
        {
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
	int i;
	
	if (argc == 1)
	{
		open_and_check_dir("./");
	}
	else if (argc == 2)
	{
		open_and_check_dir(argv[1]);
	}
	else
	{
		for(i = 1; i < argc; i++)
		{
			print_str(argv[i]);
			print_str(":\n");
			open_and_check_dir(argv[i]);
			print_char('\n');
		}
	}
	return (0);
}
