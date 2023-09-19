#include "shell.h"

/**
 * _isdigit - Check if a string  is all digits (0-9)
 * @number: number to be checked
 *
 * Return: 1 if number is a digit, 0 otherwise
 */
int _isdigit(char *number)
{
	int i = 0;

	for (; number[i] != '\0'; i++)
	{
		if (number[i] < '0' || number[i] > '9')
			return (-1);
	}
	return (0);
}
/**
 * _atoi - Converts a string to an integer.
 * @str: The input string to convert.
 *
 * Return: The integer value of the input string.
 */

int _atoi(char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i++] == '-') ? -1 : 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
