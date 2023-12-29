#include "main.h"

/**
 * execute - It executes command path.
 * @args: Cmd arguments.
 * Return: Exit status.
 */
int execute(char **args)
{
	int id = fork(), stat;

	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&stat);
		if (WIFEXITED(stat))
			stat = WEXITSTATUS(stat);
	}

	return (stat);
}
