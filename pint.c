#include "monty.h"

/**
 * pint - prints the value at the top of the stack, followeb by a new line
 * @stack: pointer to linked list stack
 * @num_line: number of line opcode occurs on
 */
void pint(stack_t **stack, unsigned int num_line)
{
	int num;

	if (stack == NULL || *stack == NULL)
	{
		printf("L%d: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	printf("%d\n", num);
}
