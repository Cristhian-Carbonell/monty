#include "monty.h"

/**
 * isint - checks if a string can be converted to an integer
 * @str: string to be checked
 *
 * Return: 0 if string can be converted to integer, 1 if not
 */
int isint(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
       	{
		if (isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}
