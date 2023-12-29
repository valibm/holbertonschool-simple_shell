#include "main.h"

/**
 * find_path - It searches among the path
 * @command: cmd
 * Return: Returns path if succesfull, NULL otherwise.
 */
char *find_path(char *command)
{
	char *path = _getenv("PATH"), *concatanated = NULL, *copied;
	char **splitted;
	int i = 0, path_len = 0;
	struct stat info;

	if (stat(command, &info) == 0)
		return (command);

	copied = malloc(strlen(path) + 1);

	copied = strcpy(copied, path);
	splitted = split(copied, ":");

	while (splitted[i])
	{
		path_len = strlen(splitted[i]);

		if (splitted[i][path_len - 1] != '/')
			concatanated = strcat(splitted[i], "/");

		concatanated = strcat(splitted[i], command);

		if (stat(concatanated, &info) == 0)
			break;

		i++;
	}

	free(copied);

	if (!splitted[i])
	{
		free(splitted);
		return (NULL);
	}

	free(splitted);
	return (concatanated);
}
