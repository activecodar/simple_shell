#include "main.h"


char **lsh_split_line(char *line)
{
	int buff_size = LSH_TOK_BUFF_SIZE, position = 0;
	char **tokens = malloc(buff_size * sizeof(char *));
	char *token;

	if(!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}
	/**
	 * Returns pointer to first token
	 * */
	token = strtok(line, LSH_TOK_DELIM);

	/**
	* Store each pointer produced by strtok in an array of char pointers
	* */
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= buff_size)
		{
			buff_size += LSH_TOK_BUFF_SIZE;
			tokens = realloc(tokens, buff_size * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "lsh: allocation error\n");
				exit(EXIT_FAILURE);
			}

		}

		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return tokens;
}
