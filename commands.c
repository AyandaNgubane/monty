#include "monty.h"

/**
 * push - a function that inserts to the stack
 * @stack: head of list
 * @line_number: line number
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *value;
	int n;
	stack_t *list;

	value = strtok(NULL, " \n\r\t");
	if (is_number(value) || !value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(value);
	list = add_node(stack, n);
	/*free_list(list);*/
}
/**
 * is_number - checks if string is a number
 * @str: string
 * Return: 0 if succesful
 */
int is_number(char *str)
{
	int i = 0;

	while (i)
	{
		if (isdigit(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
/**
 * add_node - adds a new node at the beginning of a list
 * @head: head of node
 * @n: data
 * Return: address of element, or NULL if failed
 */
stack_t *add_node(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
/**
  * free_list - Free a doubly linked list
  * @head: The head of the doubly linked list
  *
  * Return: void
  */
void free_list(stack_t *head)
{
	stack_t *current = head, *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
/**
 * display - function that prints all the elements
 * @stack: list
 * @line_number: line number
 * Return: void
 */
void display(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
