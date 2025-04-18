#include "main.h"

/**
 * execute_command - Executes the user command using execve.
 * @command: Command entered by the user.
 * @args: Array of arguments for the command.
 * Return: Void.
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
			perror("./shell");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
}
