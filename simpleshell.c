#include "main.h"

/**
  * main - simple UNIX command interpreter.
  *
  * Return: -1 if failure, 0 otherwise.
  */

int main(void)
{
	size_t count = 0, i, inputs = 1, *inputptr = &inputs;
	ssize_t f;
	char *buf = NULL, *token, *dup, **argv;

	for (; 1; inputs++)
	{
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
		f = getline(&buf, &count, stdin);
		if (f == -1)
		{
			free(buf);
			return (0); }
		if (_strcmp(buf, "\n") == 0)
		{
			free(buf), buf = NULL;
			continue; }
		buf[f - 1] = '\0';
		argv = malloc(sizeof(char *));
		if (argv == NULL)
		{
			free(buf);
			return (0); }
		dup = _strdup(buf), token = strtok(dup, " \t"), argv[0] = token;
		if (argv[0] == NULL || token == NULL)
		{
			free(argv), free(dup);
			continue; }
		if (_strcmp(argv[0], "exit") == 0)
		{
			free(argv), free(dup), free(buf);
			return (0); }
		for (i = 1; token; i++)
		{
			token = strtok(NULL, " \t");
			argv = _realloc(argv, i * sizeof(char *), (i + 1) * sizeof(char *));
			argv[i] = token; }
		argv = _realloc(argv, i * sizeof(char *), (i + 1) * sizeof(char *));
		argv[i] = NULL, executioner(argv, inputptr), free(dup); }	
	return (0); }
