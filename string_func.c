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

/**
 * str_cmp - Function that compares two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: 0 if str1 = str2
 */

int str_cmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}

	if (*str == '\0' && *str2 != '\0')
		return (-(*str2));
	else if (*str1 != '\0' && *str2 == '\0')
		return (*str1);

	return (0);
}
