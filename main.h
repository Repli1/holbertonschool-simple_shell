#ifndef main_h
#define main_h

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

/* String functions */

char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
void _memcpy(void *dest, void *src, size_t n);

/* Auxiliar functions */

void _printenv(void);
char *pathfinder(char *str);
char *_getenv(const char *name);
void *_realloc(void *ptr, size_t originalLength, size_t newLength);
int executor(char **argv, size_t *inputs);
int forker(char *finder, char **argv, size_t *inputs);
int find_file(const char *file_name, DIR *dr);

/* Declaration of environ */

extern char **environ;

#endif
