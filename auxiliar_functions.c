#include "main.h"
#include <string.h>

/**
  * _realloc - reallocates a memory block using malloc and free.
  * @ptr: Pointer to the memory previously allocated with malloc(old_size).
  * @oldSize: Size in bytes of the allocated space for ptr.
  * @newSize: New size in bytes of the new memory block.
  *
  * Return: If new_size is 0, returns NULL, if ptr is NULL returns allocated
  * memory of size newSize or if newSize is bigger than oldSize retuns ptr.
  * Otherwise, returns ptr.
  */

void *_realloc(void *ptr, size_t oldSize, size_t newSize)
{
	void *newptr = malloc(newSize);

	if (newSize == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
	{
		return (malloc(newSize));
	}
	else if (newSize <= oldSize)
	{
		return (ptr);
	}
	else
	{
		if (newptr)
		{
			_memcpy(newptr, ptr, oldSize);
			free(ptr);
		}
		return (newptr);
	}
}

/**
  * pathfinder - handle the PATH for the given command name.
  * @str: Command name string.
  *
  * Return: The entire PATH of str if it exists, str if not.
  */

char *pathfinder(char *str)
{
	char *p = _getenv("PATH"), *dup2 = _strdup(p);
	char *token = strtok(dup2, ":"), *dup = NULL;
	struct stat st;

	free(p - 5);
	while (token)
	{
		dup = _strdup(token);
		dup = _realloc(dup, _strlen(dup) + 1, _strlen(dup) + 2);
		_strcat(dup, "/");
		dup = _realloc(dup, _strlen(dup) + 1, _strlen(dup) + 1 + _strlen(str));
		_strcat(dup, str);
		if (stat(dup, &st) == 0)
		{
			free(dup2);
			return (dup);
		}
		token = strtok(NULL, ":");
		free(dup);
	}
	free(dup2);
	return (str);
}

/**
  * _getenv - Get an environment variable value by its name.
  * @name: name of the environment variable to find.
  *
  * Return: The environment variable value, NULL otherwise.
  */

char *_getenv(const char *name)
{
	int i;
	char *dup;

	for (i = 0; environ[i]; i++)
	{
		dup = _strdup(environ[i]);
		strtok(dup, "=");
		if (_strcmp(dup, name) == 0)
		{
			dup = strtok(NULL, "=");
			return (dup);
		}
		free(dup);
	}
	return (NULL);
}

/**
  * executioner - executes the given command or prints error in other case.
  * @argv: Array of strings with the input given.
  *
  * Return: 0 if it works, -1 otherwise.
  */

int executioner(char **argv, size_t *inputs)
{
	int status;
	char *finder, *pathname, *ptr;
	struct stat st;
	pid_t child_pid;

	finder = pathfinder(argv[0]);
	if (stat(finder, &st) == 0)
	{
		if (_strcmp(finder, argv[0]) != 0)
			free(finder);
		child_pid = fork();
		if (child_pid == -1)
			return (-1);
		inputs++;
		if (child_pid == 0)
			execve(pathfinder(argv[0]), argv, environ);
		free(argv);
		wait(&status);
	}
	else
	{
		pathname = _getenv("_");
		write(2, pathname, _strlen(pathname));
		write(2, ": ", 2);
		ptr = get_number(*inputs, 10);
		write(2, ptr, strlen(ptr));
		write(2, ": ", 2);
		write(2, argv[0], _strlen(argv[0]));
		write(2, ": not found\n", 12);

		free(pathname - 2);
		free(argv);
	}
	return (0);
}

char *get_number(unsigned int num, int base)
{

	static char set[16] = "0123456789abcdef";
	static char aux[64];
	char *ptraux = NULL;
	int remainder = 0;

	ptraux = &aux[63];
	*ptraux = '\0';
	if (num == 0)
		*--ptraux = '0';
	for ( ; num; )
	{
		remainder = num % base;
		*--ptraux = set[remainder];
		num = num / base;
	}
	return (ptraux);
}
