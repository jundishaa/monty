#include "monty.h"


/**
 *main -main function
 *@argc: argument count
 *@argv: argument vector
 *Return: an integer
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
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
		if (line[0] != '#' && line[0] != '\n')
			execute(line, &stack, line_number, file);
	}
	free(line);
	fclose(file);
	return (0);
}

