#include "monty.h"

/**
 * free_line - frees line and file
 * @stack: stack to free
 * @line: line to free from getline
 * @file: file pointer to free
 */
void free_line(stack_t *stack, char *line, FILE *file)
{
	if (stack != NULL)
		free_stack(&stack);
	free(line);
	fclose(file);
}

/**
 * free_stack - frees a stack_t stack
 * @stack: stack to be freed
 */
void free_stack(stack_t **stack)
{
	stack_t *actual;

	while (*stack != NULL)
	{
		actual = *stack;
		*stack = (*stack)->next;
		free(actual);
	}
}
