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
	char *args[] = {NULL};
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		line[strcspn(line, "\n")] = 0;

		if (line[0] != '\0')
		{
			args[0] = line;
			execute_command(line, args);
		}
	}
	free(line);
	return (0);
}
