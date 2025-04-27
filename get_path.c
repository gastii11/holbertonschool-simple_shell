#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 * get_path - Obtiene el valor de la variable de entorno PATH sin usar getenv
 * @envp: Array de variables de entorno
 * Return: El valor de PATH o NULL si no se encuentra
 */
char *get_path(char **envp)
{
	int i;
	for (i = 0; envp[i]; i++)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			return envp[i] + 5;
	}
	return (NULL);
}
