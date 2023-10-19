#include "monty.h"

/**
 * pop - removes top element
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack, *temp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = new;
	if (new->next)
	{
		new = new->next;
		new->prev = temp->prev;
		*stack = new;
	}
	else
	{
		*stack = NULL;
	}
	free(temp);
}
void swap(stack_t **stack, unsigned int line_number)
{
	size_t container = 0, len = 0;

	len = list_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		container = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = container;
	}
}
/**
 * list_len - function that returns number of elements
 * @h: list
 * Return: number of nodes
 */
size_t list_len(stack_t *h)
{
	size_t nodes = 0;

	while (h)
	{
		h = h->next;
		nodes++;
	}
	return (nodes);
}
