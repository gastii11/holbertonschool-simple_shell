#include "main.h"
#include <string.h>

/**
 * print_prompt - Prints shell prompt.
 */
void print_prompt(void)
{
	printf("Thomas Shellby $ ");
}

/**
 * clean_newline - Removes the newline character from a string.
 * @str: Input string.
 */
void clean_newline(char *str)
{
	str[strcspn(str, "\n")] = '\0';
}

/**
 * exit_shell - Handles shell exit.
 */
void exit_shell(void)
{
	printf("\nExiting shell...\n");
	exit(EXIT_SUCCESS);
}

/**
 * print_env - Prints the current environment variables.
 */

void print_env(void)
{
	int i = 0;

	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}
