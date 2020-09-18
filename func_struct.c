#include "monty.h"

/**
 * func_struct - checks for opcode's associated function and executes it
 * @stack: pointer to stack
 * @num_line: line number of opcode from user input
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
void func_struct(stack_t **stack, unsigned int num_line)
{
	int i;
	instruction_t func_stack[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	for (i = 0; i < 6; i++)
	{
		if (strcmp(var_op.optoke[0], func_stack[i].opcode) == 0)
		{
			(func_stack[i].f)(stack, num_line);
			return;
		}
	}
	if (i == 6)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", num_line, var_op.optoke[0]);
		exit(EXIT_FAILURE);
	}
}
