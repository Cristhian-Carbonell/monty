#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the
 * second top element of the stack
 * @stack: pointer to linked list stack
 * @num_line: number of line opcode occurs on
 */
void sub(stack_t **stack, unsigned int num_line)
{
	stack_t *n1, *n2;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	n1 = *stack;
	n2 =n1->next;
	if (n2 == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	n2->n = n2->n - n1->n;
	*stack = n2;
	n2->prev = NULL;
	free(n1);
}
