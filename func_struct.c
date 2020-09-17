#include "monty.h"

/**
 * func_struct - checks for opcode's associated function and executes it
 * @opcode: opcode form user input
 * @stack: pointer to stack
 * @num_line: line number of opcode from user input
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int func_struct(char *opcode, stack_t **stack, unsigned int num_line)
{
	int i = 0;
	instruction_t func_stack[] = {
		{"pall", pall},
        {"pint", pint},
		{NULL, NULL}
	};

	while (func_stack[i].opcode != NULL)
	{
		if (strcmp(opcode, func_stack[i].opcode) == 0)
		{
			(func_stack[i].f)(stack, num_line);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", num_line, opcode);
	exit(EXIT_FAILURE);
}
