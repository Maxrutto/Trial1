#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define DELIMITERS " \t\n"

/**
 * main - The entry point to our program
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_no);
	FILE *fp;
	char *lines[2] = {NULL, NULL};
	ssize_t no_of_lines =0;
	size_t size = 1024;

	fp = f_read(argc, argv);
	init_var(fp);
	no_of_lines = getline(&var.buf, &size, fp);
	while(no_of_lines != -1)
	{
		lines[0] = strtok(var.buf, DELIMITERS);
		if (lines[0] && lines[0][0] != '#')
		{
			f = use_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: unknown instruction %s\n", var.cont, lines[0]);
				free_var();
				exit(EXIT_FAILURE);
			}
			var.arg = strtok(NULL, DELIMITERS);
			f(var.h, var.cont);
		}
		no_of_lines = getline(&var.buf, &size, fp);
		var.cont++
	}

	free_var();

	return (0);
}
