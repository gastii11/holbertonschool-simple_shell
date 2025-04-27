#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * execute_command - Ejecuta un comando en el sistema
 * @cmd: Comando ingresado por el usuario
 * @args: Argumentos del comando
 * @envp: Variables de entorno
 */
void execute_command(char *cmd, char *args[], char *envp[])
{
	pid_t pid;
	int status;
	char *path, *p_copy, *token, full_path[256];

	if (!strcmp(cmd, "exit"))
	{
		exit_shell();
		return;
	}
	if (strchr(cmd, '/'))
	{
		execve(cmd, args, envp), perror("./Thomas_Shellby");
		exit(EXIT_FAILURE);
	}
	path = get_path(envp);
	if (!path)
		return;

	p_copy = malloc(strlen(path) + 1);
	if (!p_copy)
		return;
	strcpy(p_copy, path);
	token = strtok(p_copy, ":");
	while (token)
	{
		sprintf(full_path, "%s/%s", token, cmd);
		if (!access(full_path, X_OK))
		{
			pid = fork();
			if (!pid)
				execve(full_path, args, envp), perror("./Thomas_Shellby");
					exit(EXIT_FAILURE);
			wait(&status), free(p_copy);
			return;
		}
		token = strtok(NULL, ":");
	}
	free(p_copy), fprintf(stderr, "%s: comando no encontrado\n", cmd);
}



























































