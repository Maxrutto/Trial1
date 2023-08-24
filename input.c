#include <stdio.h>
#include "monty.h"

/**
 * f_read - Checks if a file exists and read or opened
 * @argc: Argument count
 * @argv: Arguments
 *
 * Return: File pointer
 */

FILE *f_read(int argc, char **argv)
{
	FILE *fp;

	if (argc > 2 || argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fp);
}
