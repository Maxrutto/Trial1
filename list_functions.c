#include "monty.h"

/**
 * add_node_start - Adds a node at the beginning of
 * the doubly linked list
 * @n: Data to store in the new node
 * @h: Pointer to the head of the list
 *
 * Return: pointer to the node
 */
stack_t *add_node_start(stack_t **h, const int n)
{
	stack_t *new_node;

	if (h == NULL)
		return (NULL);

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;

	if (*h == NULL)
	{
		new_node->next = NULL;
		*h = new_node;
		return (new_node);
	}

	(*h)->prev = new_node;
	new_node->next = *h;
	*h = new_node;

	return (new_node);
}

/**
 * add_node_end - Adds a node at the end of a
 * doubly linked list
 * @n: data to store in the new node
 * @h: pointer to the head of the list
 *
 * Return: pointer to the new node
 */
stack_t *add_node_end(stack_t **h, const int n)
{
	stack_t *new_node, *temp;

	if (h == NULL)
		return (NULL);

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_var();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (*h == NULL)
	{
		new_node->prev = NULL;
		*h = new_node;
		return (new_node);
	}

	temp = *h;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}
