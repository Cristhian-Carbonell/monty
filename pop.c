#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: linked lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void pop(stack_t **stack, unsigned int num_line)
{
	stack_t *actual;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", num_line);
		exit(EXIT_FAILURE);
	}
	actual = (*stack)->next;
	free(*stack);
	*stack = actual;
}
