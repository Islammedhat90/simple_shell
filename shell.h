#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

int free_arr(char **arr);
char **com_arr(char *line, char *delim);
void fill_array(char **commands, char *copy, char *delim);
char *_getenv(char *var);
char *handle_line(char *line);
int line_checker(char *line);
char *get_path(char *command);
char *handle_path(char **commands, int count, char **env);
int print_error(char *command, int count);
char *print_number(int count);
void print_commanderr(char *command, int count);
int command_count(char **commands);

int builtin_checker(char *command);
int handle_builtin(int m, char **commands, int count, char *handledline);
void my_exit(char **commands, int count, char *handledline);
void my_env(void);
int _isdigit(char *number);
int _atoi(char *str);

#endif

