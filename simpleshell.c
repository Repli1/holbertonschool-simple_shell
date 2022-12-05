#include "main.h"

/**
  * main - simple UNIX command interpreter.
  *
  * Return: -1 if failure, 0 otherwise.
  */

int main(void)
{
	size_t count = 0, i;
	ssize_t f;
	char *buf = NULL, *token, *dup, **argv;

	while (1)
	{
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
		f = getline(&buf, &count, stdin);
		if (buf == NULL)
			return (-1);
		if (f == -1)
		{
			free(buf);
			return (-1);
		}
		buf[f - 1] = '\0';
		if (_strcmp(buf, "exit") == 0)
		{
			free(buf);
			return (0);
		}
		argv = malloc(sizeof(char *));
		if (argv == NULL)
		{
			free(buf);
			return (-1);
		}
		dup = _strdup(buf);
		token = strtok(dup, " ");
		argv[0] = token;
		for (i = 1; token; i++)
		{
			token = strtok(NULL, " ");
			argv = _realloc(argv, i * 8, (i + 1) * 8);
			argv[i] = token;
		}
		argv = _realloc(argv, i * 8, (i + 1) * 8);
		argv[i] = NULL, executioner(argv), free(dup);
	}
	return (0);
}
