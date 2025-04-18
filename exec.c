#include "main.h"

/**
 * execute_command - Executes the user command using execve.
 * @command: Command entered by the user.
 *
 * Return: Void.
 */
void execute_command(char *command, char *args[])
{
    pid_t pid;

    
    pid = fork();

    if (pid == 0)
    {
	    if (execve(command, args, environ) == -1)
	    {
		    perror("Error al ejecutar el comando");
		    exit(EXIT_FAILURE);
	    }
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("fork failed");
	exit(EXIT_FAILURE);
    }


}

