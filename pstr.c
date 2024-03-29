#include "monty.h"
/**
 *pstr - to prints the string from the stack
 *@stack: this is the stack
 *@line_number: line number
 *Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp != NULL && temp->n > 0 && temp->n <= 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}

