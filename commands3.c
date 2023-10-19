#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	(void) line_number;

	while (new != NULL)
	{
		if (new->n > 127 || new->n <= 0)
			break;
		printf("%c", new->n);
		new = new->next;
	}
	printf("\n");
}
/**
 * rotl - rotates the stack to the top
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	int data = 0;
	(void) line_number;

	if (new)
	{
		while (new->next)
		{
			data = new->n;
			new->n = new->next->n;
			new->next->n = data;
			new = new->next;
		}
	}
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void) line_number;

	if (*stack)
	{
		new = *stack;

		while (new->next)
			new = new->next;
		new->prev->next = NULL;
		new->next = *stack;
		*stack = new;
	}
}
