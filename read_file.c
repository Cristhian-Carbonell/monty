#include "monty.h"

/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathame to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t *stack)
{
	FILE *file;
	char *delimiter = " \n", *buffer = NULL;
	unsigned int num_line = 0;
	size_t lenght;
	stack_t *tmp;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &lenght, file) != -1)
	{
		num_line++;
		var_op.optoke = split(buffer, delimiter);
		if (var_op.optoke[0] != NULL)
		{
			if (var_op.optoke[0][0] == '#')
			{
				free(var_op.optoke);
				continue;
			}
			else
				func_struct(&stack, num_line);
			free(var_op.optoke);
		}
		else
		{
			free(var_op.optoke);
			continue;
		}
	}
	free(buffer);
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	fclose(file);
}
