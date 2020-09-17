#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followeb by a new line
 * @stack: pointer to linked list stack
 * @num_line: number of line opcode occurs on
 */
void pint(stack_t **stack, unsigned int num_line)
{
	stack_t *actual = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", actual->n);
}
