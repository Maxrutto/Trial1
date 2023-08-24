#include "monty.h"

global_t var;

/**
 * init_var - Initializing the global variables
 *
 * @fp: File descriptor for the open file
 *
 * Return: void
 */

void init_var(FILE *fp)
{
	var.cont = 1;
	var.lifo = 1;
	var.h = NULL;
	var.fp = fp;
	var.buf = NULL;
	var.arg = NULL;
}
