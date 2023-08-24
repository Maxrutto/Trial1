#include "monty.h"

/**
 * is_int - Checks if a string is a valid integer
 * @str: The input to check
 * Return: 1 if the string is a number, 0 otherwise.
 */
int is_int(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-')
		str++;

	while (*str != '\0')
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
