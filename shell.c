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
	size_t len = 0;
	ssize_t nread;
	pid_t pid;

	while (1)
	{
		printf("$ ");

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			printf("\n");
			break;
		}

		line[strcspn(line, "\n")] = 0;

		pid = fork();
		if (pid == 0)
		{
			if (execve(line, &line, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{
			perror("fork failed");
		}
		else
		{
			wait(NULL);
		}
	}
	free(line);
	return (0);
}
