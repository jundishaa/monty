#include "monty.h"
/**
 *rotr - to rotate the top element from the stack
 *@stack: this is the stack
 *@line_number: line number
 *Description: The top element of the stack becomes the last one,
 *and the second top element of the stack becomes the first one.
 *
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	last = NULL;

	while (temp->next)
	{
		last = temp;
		temp = temp->next;
	}

	temp->next = *stack;
	(*stack)->prev = temp;
	last->next = NULL;
	*stack = temp;
}

