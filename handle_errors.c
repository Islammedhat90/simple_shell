#include "shell.h"


/**
 * print_error - function that prints error to stdout in shell format
 * @command: command that caused the error
 * @count: line count.
 * Return: 0 if succesful.
*/

int print_error(char *command, int count)
{
	char *number = print_number(count);

	if (command != NULL)
	{
		write(STDERR_FILENO, "./hsh", strlen("./hsh"));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, number, strlen(number));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "exit", strlen("exit"));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, "Illegal number: ", strlen("Illegal number: "));
		write(STDERR_FILENO, command, strlen(command));
		write(STDERR_FILENO, "\n", 1);
	}
	free(number);
	return (0);
}


/**
 * print_commanderr - Prints a command error message to standard error.
 * @command: The command that triggered the error.
 * @count: The error count.
 */

void print_commanderr(char *command, int count)
{
	char *number = print_number(count);

	write(STDERR_FILENO, "./hsh", strlen("./hsh"));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, number, strlen(number));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, strlen(command));
	write(STDERR_FILENO, ": ", 2);
	write(2, "not found", strlen("not found"));
	write(2, "\n", 1);
	free(number);
}

/**
 * print_cderror - Print a "cd" command error message to standard error.
 * @command: The command that resulted in the error.
 * @count: The count of executed commands.
 * Return: nothing.
 */

void print_cderror(char *command, int count)
{
	char *number = print_number(count);

	write(STDERR_FILENO, "./hsh", strlen("./hsh"));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, number, strlen(number));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "cd: ", strlen("cd: "));
	write(2, "can't cd to ", strlen("can't cd to "));
	write(2, command, strlen(command));
	write(2, "\n", 1);
	free(number);
}
/**
 * print_number - Convert an integer to a string.
 * @n: The integer to convert.
 *
 * Return: A pointer to the newly allocated string representation,
 *         or NULL if memory allocation fails.
 */

char *print_number(int n)
{
	int num_copy = n;
	int digit_count = 1;
	int length = 0;
	int i = 0;
	char *result;

	while (num_copy > 9)
	{
		num_copy /= 10;
		digit_count *= 10;
		length++;
	}
	length++;
	result = (char *)malloc(length + 1);
	if (result == NULL)
		return (NULL);
	for (; digit_count >= 1; digit_count /= 10)
		result[i++] = ((n / digit_count) % 10) + '0';
	result[length] = '\0';
	return (result);
}
