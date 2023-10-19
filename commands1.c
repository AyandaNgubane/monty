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
/**
 * swap - swaps top 2 elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
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
/**
 * add - adds top 2 elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int container = 0;
	size_t len = 0;
	stack_t *temp = *stack;

	len = list_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		container = temp->n;
		temp->n = temp->next->n;
		container = container + temp->n;
		temp->next->n = container;
		*stack = temp->next;
		free(temp);
	}
}
/**
 * nop - does nothing
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
