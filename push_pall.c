#include "monty.h"

/**
 * push - pushes an integer value onto the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode in the bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n;
	char *endptr;
	stack_t *new_node;

	n = atoi(bytecode + opcodes[*stack].opcode_len);

	if (*bytecode == '\0' || *endptr != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * pall - prints all the values on the stack from the top
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode in the bytecode file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		return;
	}

	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

