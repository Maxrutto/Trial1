#include "monty.h"

/**
 * free_doubly - frees the linked list
 *
 * @h: head of the list
 * Return: void
 */
void free_doubly(stack_t *h)
{
	stack_t *temp;

	while ((temp = h) != NULL)
	{
		h = h->next;
		free(temp);
	}
}
