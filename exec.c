#include "main.h"

/**
 * execute_command - Executes the user command using execve.
 * @command: Command entered by the user.
 *
 * Return: Void.
 */
void execute_command(char *command)
{
    pid_t pid = fork();
    char **args;

    args = malloc(2 * sizeof(char *));
    if (args == NULL)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    args[0] = command;
    args[1] = NULL;

    pid = fork();

    if (pid == 0)
    {
	execve(args[0], args, environ);
        perror("Error");
        free(args);
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("fork failed");
        free(args);
	exit(EXIT_FAILURE);
    }

    free(args);
}

