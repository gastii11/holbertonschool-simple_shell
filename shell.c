#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - simple shell
 * Return: retorna 0
 */
int main(int argc __atribute__((unused)), char **argv, char **envp)
{
	char *line = NULL, **args, *token;
	size_t len = 0;
	ssize_t nread;
	int i = 0;
	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
			write(STDOUT_FILENO, "Thomas Shellby $ ", 17);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		line[strcspn(line, "\n")] = 0;

		args = malloc(10 * sizeof(char *));
		if (!args)
			exit(EXIT_FAILURE);

		i = 0;
		token = strtok(line, " ");
		while (token && i < 9)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (args[0] && strcmp(args[0], "exit") == 0)
		{
			free(args);
			free(line);
			exit(0);
		}

		if (args[0] && strcmp(args[0], "env") == 0)
		{
			print_env();
			free(args);
			continue;
		}

		if (args[0])
			execute_command(args[0], args);

		free(args);
	}
	free(line);
	return (0);
}
