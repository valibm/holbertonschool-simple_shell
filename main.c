#include "main.h"

/**
 * main - open shell, project base
 * Return: int
 */
int main(void)
{
	char *buffer = NULL, **args;
	size_t read_s = 0;
	ssize_t buff_s = 0;
	int exit_stat = 0;

	while (1)
	{
		if (isatty(0))
			printf("hsh$ ");

		buff_s = getline(&buffer, &read_s, stdin);
		if (buff_s == -1 || strcmp("exit\n", buffer) == 0)
		{
			free(buffer);
			break;
		}
		buffer[buff_s - 1] = '\0';

		if (strcmp("env", buffer) == 0)
		{
			_env();
			continue;
		}

		if (check_buff(buffer) == 1)
		{
			exit_stat = 0;
			continue;
		}

		args = split(buffer, " ");
		args[0] = find_path(args[0]);

		if (args[0] != NULL)
			exit_stat = execute(args);
		else
			perror("Error");
		free(args);
	}
	return (exit_stat);
}
