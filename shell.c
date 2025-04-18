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
	char *line = NULL, **args, *token;
	size_t len = 0;
	ssize_t nread;
	int i = 0;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		line[strcspn(line, "\n")] = 0;

		args = malloc(10 * sizeof(char *));
		if (!args)
			exit(EXIT_FAILURE);
		
		token = strtok(line, " ");
		while (token && i < 9)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (args[0])
			execute_command(args[0], args);

		free(args);
	}
	free(line);
	return (0);
}
