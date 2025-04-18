#ifndef EXEC_H
#define EXEC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void execute_command(char *command, char *args[]);
void print_prompt(void);
void clean_newline(char *str);
void exit_shell(void);

#endif /* EXEC_H */

