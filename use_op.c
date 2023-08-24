#include "monty.h"

/**
 * use_opcodes - Matches the correct opcode to perfom
 * @op: opcode run
 *
 * Return: Pointer to the opcode function
 */

void (*use_opcodes(char *op))(stack_t **stack, unsigned int line_no)
{
	int i;

	instruction_t instruct[] = {
		{"push", push_op},
		{"pall", pall_op},
		{NULL, NULL}
	};

	for (i = 0; instruct[i].opcode; i++)
	{
		if (str_cmp(instruct[i].opcode, op) == 0)
			break;
	}

	return (instruct[i].f);
}
