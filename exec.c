#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * run_command - Ejecuta un comando utilizando fork
 * @command: Comando ingresado por el usuario
 * @args: Argumentos del comando
 *
 * Return: Void
 */
void execute_command(char *command, char *args[])
{
        pid_t pid;
        int status;

        pid = fork();
        if (pid == 0)
        {
                if (execve(command, args, environ) == -1)
                {
                        perror("Error al ejecutar comando");
                        exit(EXIT_FAILURE);
                }
        }
        else if (pid > 0)
        {
                wait(&status);
        }
        else
        {
                perror("Error al crear proceso hijo");
        }
}
