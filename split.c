#include "monty.h"

/**
 * split - split a string
 * @line: string to be split
 *
 * Return: pointer to array of arrays
 */
char **split(char *line)
{
	char **tokens, *token;
	int i = 0;

	tokens = malloc(sizeof(char) * 1024);
	if (tokens == NULL)
		return (NULL);
	token = strtok(line, DELIMITER);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIMITER);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
