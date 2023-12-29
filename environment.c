#include "main.h"

/**
 * _getenv - Get environment variables.
 * @env: nvironment variable.
 * Return: Contents of environment variable.
 */
char *_getenv(char *env)
{
	int i = 0, j;
	int status;

	while (environ[i])
	{
		status = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != env[j])
				status = 0;
		}
		if (status == 1)
			break;
		i++;
	}
	return (&environ[i][j + 1]);
}

/**
 * _env - It's a function that prints the environment.
 *
 * Return: Void.
 */
void _env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
