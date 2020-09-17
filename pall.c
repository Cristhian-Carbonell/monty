#include "monty.h"

/**
 * pall - print all function
 * @stack: pointer to linked list stack
 * @num_line: number of line opcode occurs on
 */
void pall(stack_t **stack, unsigned int num_line)
{
	stack_t *actual = *stack;
	(void)num_line;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	while (actual != NULL)
	{
		printf("%d\n", actual->n);
		actual = actual->next;
	}
}
