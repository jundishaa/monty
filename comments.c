#include "monty.h"
/**
 *process_line - to check comments
 *@line: the line
 *Return:nothing
 */
void process_line(char *line)
{
	char *first_non_space_char = line;


	while (*first_non_space_char == ' ')
	{
		first_non_space_char++;
	}

	if (*first_non_space_char == '#')
	{
		return;
	}

}

