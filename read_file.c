#include "monty.h"

/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathame to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t *stack)
{
	FILE *file;
	char *line = NULL;
	char *opcode, *new_elem;
	unsigned int num_line = 0;
	size_t lenght;
	ssize_t read;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &lenght, file)) != -1)
	{
		num_line++;
		opcode = strtok(line, DELIMITERS);
		if (opcode == NULL || strncmp(opcode, "#", 1) == 0)
			continue;
		if (strcmp(opcode, "push") == 0)
		{
			new_elem = strtok(NULL, DELIMITERS);
			push(&stack, num_line, new_elem);
		}
		else
			func_struct(opcode, &stack, num_line);
	}
	free_line(stack, line, file);
}
