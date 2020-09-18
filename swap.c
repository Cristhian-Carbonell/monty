#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: linked lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void swap(stack_t **stack, unsigned int num_line)
{
	stack_t *n1, *n2;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	n1 = *stack;
	n2 = n1->next;
	if (n2 == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	if (n2->next == NULL)
	{
		n1->prev = n2;
		n2->next = n1;
		n1->next = NULL;
		n2->prev = NULL;
		*stack = n2;
	}
	else
	{
		n1->next = n2->next;
		n2->next->prev = n1;
		n1->prev = n2;
		n2->next = n1;
		n2->prev = NULL;
		*stack = n2;
	}
}
