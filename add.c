#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

    /* Check if stack contains less than two elements */
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = sum;
}

