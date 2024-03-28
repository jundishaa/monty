#include "monty.h"
/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

    /* Swap values */
	temp = first->n;
	first->n = second->n;
	second->n = temp;

    /* Swap next pointers (if not top two elements) */
	if (second->next)
	{
		second->next->prev = first;
	}
	first->next = second->next;
	second->next = first;

    /* Update stack head */
	*stack = second;
}
