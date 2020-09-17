#include "monty.h"

/**
 * split - split a string
 * @line: string to be split
 * @delimiter: delimiter
 *
 * Return: pointer to array of arrays
 */
char **split(char *line, char *delimiter)
{
	char **tokens, *token;
	int i = 0;

	tokens = malloc(sizeof(char) * 1024);
	if (tokens == NULL)
		return (NULL);
	token = strtok(line, delimiter);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delimiter);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
