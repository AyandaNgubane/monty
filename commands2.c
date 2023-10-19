#include "monty.h"

/**
 * _sub - subtracts top element from 2nd element
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	int container = 0;
	size_t len = 0;
	stack_t *temp = *stack;

	len = list_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		container = temp->n;
		temp->n = temp->next->n;
		container = temp->n - container;
		temp->next->n = container;
		*stack = temp->next;
		free(temp);
	}
}
/**
 * _div - divides 2nd element by top element
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int container = 0;
	size_t len = 0;
	stack_t *temp = *stack;

	len = list_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		if (temp->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		container = temp->n;
		temp->n = temp->next->n;
		container = temp->n / container;
		temp->next->n = container;
		*stack = temp->next;
		free(temp);
	}
}
/**
 * _mul - multiplies top 2 elements
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	int container = 0;
	size_t len = 0;
	stack_t *temp = *stack;

	len = list_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		container = temp->n;
		temp->n = temp->next->n;
		container = container * temp->n;
		temp->next->n = container;
		*stack = temp->next;
		free(temp);
	}
}
/**
 * _mod - gets remainder of division of 2nd element by top element
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	int container = 0;
	size_t len = 0;
	stack_t *temp = *stack;

	len = list_len(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		if (temp->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		container = temp->n;
		temp->n = temp->next->n;
		container = temp->n % container;
		temp->next->n = container;
		*stack = temp->next;
		free(temp);
	}
}
/**
 * pchar - prints the value at the top of the stack
 * @stack: head of stack
 * @line_number: line number
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
