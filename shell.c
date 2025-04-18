#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - simple shell
 * Return: retorna 0
 */

int main(void)
{
	char *line = NULL;
	char **args;
	size_t len = 0;
	ssize_t nread;
	int i = 0;
	char *token;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		line[strcspn(line, "\n")] = 0;

		args = malloc(sizeof(char *));
		if (!args)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}

		token = strtok(line, " ");
		i = 0;
		while (token)
		{
			args = realloc(args, (i + 1) * sizeof(char *));
			if (!args)
			{
				perror("realloc failed");
				exit(EXIT_FAILURE);
			}
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (args[0])
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				break;
			}
			execute_command(args[0], args);
		}
		free(args);
	}
	free(line);
	return (0);
}
