#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *find_path(char *command);
char *_getenv(char *env_var);
void _env(void);
int execute(char **args);
int check_buff(char *buff);
char **split(char *str, char *sep);

extern char **environ;

#endif
