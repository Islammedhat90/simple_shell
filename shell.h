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
int delimcheck(char c, const char *delim);
char *_strtok(char *line, const char *delim);
int line_checker(char *line);
char *get_path(char *command);
char *handle_path(char **commands, int count, char **env);
void _execute(char *path, char **commands, char **env, int count);
int print_error(char *command, int count);
char *print_number(int count);
void print_commanderr(char *command, int count);
void print_cderror(char *command, int count);
int command_count(char **commands);

int builtin_checker(char *command);
int handle_builtin(int m, char **commands,
int count, char *handledline, char **env);
void my_exit(char **commands, int count, char *handledline);
void my_env(char **env);
int _setenv(char *var, char *value, char **env);
int my_setenv(char **commands, char **env);
int _unsetenv(char **commands, char **env);
int my_cd(char **commands, char **env, int count);
int _isdigit(char *number);
int _atoi(char *str);

int handle_operator(char *line, int count, char **env, char *delim);
int handle_dollar(char *line, int count, char **env);
int operatorcheck(char *line, int count, char **env);

#endif

