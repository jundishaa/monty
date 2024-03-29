#include "monty.h"
/**
 *stack - to rotate the top element from the stack
 *@stack: this is the stack
 *@line_number: line number
 * Description: The top element of the stack becomes the last one,
 *and the second top element of the stack becomes the first one.
 *
 */
void set_stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack)
		(*stack)->mode = 0;
}

/**
 *queue - to rotate the top element from the stack
 *@stack: this is the stack
 *@line_number: line number
 * Description: The top element of the stack becomes the last one,
 *and the second top element of the stack becomes the first one.
 *
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack && *stack)
		(*stack)->mode = 1;
}

