#include "monty.h"
/**
 * pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: value of the new node
 * Return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
    /* Check if stack is empty */
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

