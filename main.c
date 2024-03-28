#include "monty.h"
global_t global_variable;
/**
 *main -main function
 *@argc: argument count
 *@argv: argument vector
 *Return: an integer
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL, *token;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		token = strtok(line, "\n\t\r ");
		global_variable.holder = strtok(NULL, "\n\t\r ");
		if (!strcmp(token, "push"))
			push(&stack, line_number);
		else if (!strcmp(token, "pall"))
			pall(&stack, line_number);
		else if (!strcmp(token, "pint"))
			pint(&stack, line_number);
		else if (!strcmp(token, "pop"))
			pop(&stack, line_number);
		else if (!strcmp(token, "swap"))
			swap(&stack, line_number);
		else if (!strcmp(token, "add"))
			add(&stack, line_number);
		else if (!strcmp(token, "nop"))
			nop(&stack, line_number);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(file);
	return (0);
}
