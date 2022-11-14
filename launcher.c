#include "main.h"

int lsh_launch(char **args)
{
	pid_t pid;
	int status;

	/**
	 * Forks/duplicates from a parent process returns 0 for the child process but pid for the parent
	 * */
	pid = fork();

	/**
	 * child process
	 * */
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("lsh");
		}
		exit(EXIT_FAILURE);
	}

		/**
		 * Error forking
		 * */
	else if (pid < 0)
	{
		perror("lsh");
	}
		/**
		 * parent process
		 * */
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		}
		while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}
