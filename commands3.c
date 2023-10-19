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
		printf("%c\n", new->n);
		new = new->next;
	}
	printf("\n");
}
