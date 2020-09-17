#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followeb by a new line
 * @stack: pointer to linked list stack
 * @num_line: number of line opcode occurs on
 */
void pint(stack_t **stack, unsigned int num_line)
{
	stack_t *value = *stack;

	if (value == NULL)
	{
		printf("L%d: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", value->n);
}
