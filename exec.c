#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * execute_command - Busca y ejecuta un comando en el sistema
 * @command: Comando ingresado por el usuario
 * @args: Argumentos del comando
 * Return: Void
 */
void execute_command(char *command, char *args[], char *envp[])
{
	pid_t pid;
	int status;
	char *path, *path_copy, *token, full_path[256];

	if (strcmp(command, "exit") == 0)
	{
		exit_shell();
		return;
	}
	if (strchr(command, '/'))
	{
		execve(command, args, envp);
		perror("./Thomas_Shellby");
		exit(EXIT_FAILURE);
	}
	path = get_path(envp);
	if (!path)
		return;

	path_copy = malloc(strlen(path) + 1);
	if (!path_copy)
		return;
	strcpy(path_copy, path);
	token = strtok(path_copy, ":");
	while (token)
	{
		sprintf(full_path, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(full_path, args, envp);
				perror("./Thomas_Shellby");
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
				wait(&status);

			free(path_copy);
			return;
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	fprintf(stderr, "%s: comando no encontrado\n", command);
}
