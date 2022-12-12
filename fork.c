#include "main.h"

/**
 * forker - Creates a child process to execve.
 * @finder: The command to execute.
 * @argv: The array of arguments.
 * @inputs: Number of input lines.
 * Return: The exit status of the child process or 0.
 */
int forker(char *finder, char **argv, size_t *inputs)
{
	int status;
	pid_t child_pid;

	child_pid = fork(); /* Child process to execve */
	if (child_pid == -1)
		return (0);
	inputs++;
	if (child_pid == 0)
		execve(finder, argv, environ);
	if (_strcmp(argv[0], finder) != 0)
		free(finder);
	free(argv);
	wait(&status);
	return (WEXITSTATUS(status));
}
