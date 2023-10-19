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
