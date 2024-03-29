#include "monty.h"
/**
 *mul - to multiply the top element from the stack
 *@stack: this is the stack
 *@line_number: line number
 *Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n *= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}

