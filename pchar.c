#include "monty.h"
/**
 *pchar - to print the top char from the stack
 *@stack: this is the stack
 *@line_number: line number
 *Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int ascii_val;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_val = (*stack)->n;
	if (ascii_val < 0 || ascii_val > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ascii_val);
}

