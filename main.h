#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(const char *s1, const char *s2);
char *_strdup(char *str);
void _printenv(void);
char *pathfinder(char *str);
char *_getenv(const char *name);
void _printenv(void);
char *pathfinder(char *str);
void *_realloc(void *ptr, size_t originalLength, size_t newLength);
void _memcpy(void *dest, void *src, size_t n);
int executioner(char **argv, size_t *inputs);
char *get_number(unsigned int num, int base);
extern char **environ;

#endif
