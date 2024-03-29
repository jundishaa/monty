#include "monty.h"
/**
 *rot1 - to rotate the top element from the stack
 *@stack: this is the stack
 *@line_number: line number
 * Description: The top element of the stack becomes the last one,
 *and the second top element of the stack becomes the first one.
 *
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int num;

	(void)line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;

	temp = *stack;
	num = temp->n;

	while (temp->next)
	{
		temp->n = temp->next->n;
		temp = temp->next;
	}

	temp->n = num;
}
