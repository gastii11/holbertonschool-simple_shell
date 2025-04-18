#include "main.h"
#include <string.h>

/**
 * print_prompt - Prints shell prompt.
 */
void print_prompt(void)
{
	printf("$ ");
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

