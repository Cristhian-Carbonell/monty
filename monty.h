#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct mystruct_s - storing a variable here
 * @optoke: lines of opcode stored here
 * Description: this is where I am storing a variable
 * so that I can use it in multiple functions
 */
typedef struct mystruct_s
{
	char **optoke;
} mystruct_t;
mystruct_t var_op;

void read_file(char *filename, stack_t *stack);
void push(stack_t **stack, unsigned int num_line);
void func_struct(stack_t **stack, unsigned int num_line);
void pall(stack_t **stack, unsigned int num_line);
void pint(stack_t **stack, unsigned int num_line);
char **split(char *line, char *delimiter);
int isint(char *str);
void free_list(char *buffer, stack_t *tmp, stack_t *stack, FILE *file);
void pop(stack_t **stack, unsigned int num_line);
void swap(stack_t **stack, unsigned int num_line);
void add(stack_t **stack, unsigned int num_line);

#endif /* MONTY.H */
