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
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
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
