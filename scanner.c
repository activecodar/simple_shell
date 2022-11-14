#include "main.h"



char *lsh_read_line(void) {
	int buff_size = LSH_RL_BUFF_SIZE;
	int position = 0;
	char *buffer = malloc(sizeof(char) * buff_size);
	int character;

	if (!buffer)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		character = getchar();

		if(character == EOF || character == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}
		else
		{
			buffer[position] = character;
		}

		position++;

		if (position >= buff_size)
		{
			buff_size += LSH_RL_BUFF_SIZE;
			buffer = realloc(buffer, buff_size);
			if (!buffer)
			{
				fprintf(stderr, "lsh: reallocation error");
				exit(EXIT_FAILURE);
			}
		}
	}
}
