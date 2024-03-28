#include "monty.h"
/**
 *div - to divide the top element from the stack
 *@stack: this is the stack
 *@line_number: line number
 *Return: nothing
 */
void div_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->n /= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}

