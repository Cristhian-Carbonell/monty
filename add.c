#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: linked lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void add(stack_t **stack, unsigned int num_line)
{
	stack_t *n1, *n2;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	n1 = *stack;
	n2 = n1->next;
	if (n2 == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	n2->n = n2->n + n1->n;
	*stack = n2;
	n2->prev = NULL;
	free(n1);
}
