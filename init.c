#include "monty.h"

/**
 * init_var - Initializing the global variables
 *
 * @fd: File descriptor for the open file
 *
 * Return: void
 */

void init_var(FILE *fd)
{
	var.cont = 1;
	var.lifo = 1;
	var.h = NULL;
	var.fd = fd;
	var.buf = NULL;
	var.arg = NULL;
}
