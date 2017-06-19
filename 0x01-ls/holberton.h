#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

typedef struct List {
  char *str;
  struct List *next;
} List;

void free_list(List *list);
int is_cap(char c);
char normalize_char(char c);
char *str_copy(char *src);
int str_len(char *src);
int print_char(char c);
void print_str(char *str);
void print_list(List *list);
void open_and_check_dir(char *path);
int sort_dir(List **list, char *fn);
void insert_in_list(List *node, List **list);
int build_list(DIR *dir);
List *allocate_node(char *str);

#endif
