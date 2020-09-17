#include "monty.h"

/**
 * push - push int to a stack
 * @stack: linked lists for monty stack
 * @num_line: number of line opcode occurs on
 * @new_elem: value of new item on stack
 */
void push(stack_t **stack, unsigned int num_line, char *new_elem)
{
	stack_t *new = NULL;
	int i = 0;

	if (new_elem == NULL)
	{
		printf("L%d: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
	while (new_elem[i] != '\0')
	{
		if (new_elem[0] == '-' && i == 0)
			continue;
		if (isdigit(new_elem[i]) == 0)
		{
			printf("L%d: usage: push integer\n", num_line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(new_elem);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}
