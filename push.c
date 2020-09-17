#include "monty.h"

/**
 * push - push int to a stack
 * @stack: linked lists for monty stack
 * @num_line: number of line opcode occurs on
 */
void push(stack_t **stack, unsigned int num_line)
{
	stack_t *new, *tmp;

	if (var_op.optoke[1] == NULL || isint(var_op.optoke[1]) != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(var_op.optoke[1]);
	new->prev = NULL;
	tmp = *stack;
	if (tmp == NULL)
		new->next = NULL;
	else
	{
		new->next = tmp;
		tmp->prev = new;
	}
	*stack = new;
}
