#define _GNU_SOURCE
#include "monty.h"

/**
 * main - main function
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	FILE *fd = NULL;
	char *input = NULL, *tokenized = NULL;
	unsigned int line_number = 0;
	size_t buffer = 0;
	stack_t *head = NULL, *temp = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&input, &buffer, fd) != -1)
	{
		line_number++;
		tokenized = strtok(input, " \n\r\t");
		if (tokenized)
		{
			command(tokenized, &head, line_number);
		}
	}
	if (head)
	{
		temp = head;

		while (temp)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
	free(input);
	fclose(fd);
	return (0);
}
/**
 * command - function that checks the user input
 * @tokenized: tokenized input
 * @head: head of linked list
 * @line_number: file line number
 * Return: void
 */
void command(char *tokenized, stack_t **head, unsigned int line_number)
{
	instruction_t user_input[] = {
		{"push", push},
		{"pall", display},
		{NULL, NULL}
	};

	size_t i = 0;

	while (user_input[i].opcode)
	{
		if (strcmp(user_input[i].opcode, tokenized) == 0)
		{
			(user_input[i].f(head, line_number));
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, tokenized);
	exit(EXIT_FAILURE);
}
