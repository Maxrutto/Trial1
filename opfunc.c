#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "monty.h"

/**
 * push_op - Implement the push opcode
 * @stack: Double pointer to the top of the stack
 * @line_no: Line number of the command in the file
 */
void push_op(stack_t **stack, unsigned int line_no)
{
	if (!var.arg || !is_int(var.arg))
	{
		dprintf(2, "L%u: usage: push integer\n", line_no);
		free_var();
		exit(EXIT_FAILURE);
	}

	int n = atoi(var.arg);

	if (var.lifo == 1)
		add_node_start(stack, n);
	else
		add_node_end(stack, n);
}

/**
 * pall_op - Implement the pall opcode
 * @stack: Double pointer to the top of the stack
 * @line_no: Line number of the command in the file
 */
void pall_op(stack_t **stack, unsigned int line_no)
{
	(void)line_no;

	stack_t *temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
