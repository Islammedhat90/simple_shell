#include "shell.h"


/**
  * builtin_checker - function that checks if the command is built in.
  *@command: command to be checked.
  * Return: returns number if built in, -1 otherwise
  */

int builtin_checker(char *command)
{
        int i = 0;
        char *builtin[] = {"exit", "env"};

        if (command != NULL)
        {
            for (; i < 2; i++)
            {
                if (strcmp(command, builtin[i]) == 0)
                    return (i);
            }
            return (-1);
        }
        perror("NULL command");
        return (-1);
}

/**
 * handle_builtin - Handles built-in commands based on input code.
 * @m: The code representing the built-in command.
 * @commands: array of commands
 * Return: 0 if successful, -1 on error or unknown command.
 */

int handle_builtin(int m, char **commands, int count, char *handledline)
{
        if (m == -1)
            return (-1);
        switch (m)
        {
            case 0:
                    my_exit(commands, count, handledline);
                    return (0);
            case 1:
                    my_env();
                    return (1);
            default:
                    return (-1);
        }
        return (0);
}