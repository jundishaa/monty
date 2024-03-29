#include "monty.h"
/**
 *pstr - to prints the string from the stack
 *@stack: this is the stack
 *@line_number:the line number
 *Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (!*stack)
	{
		printf("\n");
		return;
	}

	temp = *stack;

	while (temp && temp->n)
	{
		if (isprint(temp->n))
		{
			printf("%c", temp->n);
		} else
		{
			break;
		}
		temp = temp->next;
	}
	printf("\n");

	/*line_number is currently unused*/
}

