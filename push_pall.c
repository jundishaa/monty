#include "monty.h"
extern global_t global_variable;

/**
 * push - pushes an integer value onto the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number of the opcode in the bytecode file
 */
void push(stack_t **stack, unsigned int line_number)
{
	int value;
	stack_t *new_node;

	value = atoi(global_variable.holder);

	if (value == 0 && global_variable.holder[0] != '0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
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
	stack_t *temp = *stack;

	(void)line_number;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
