#include "MyShell.h"

/**
 * main - SIMULATOR PROGRAM SHELL
 * Return: function will always return 0
 */

int main(void)
{
	char *buffer = NULL, **command;
	int pointer, i;

	while (1)
	{
		if (isatty(0))
			write(1, ":) ", 3);
		buffer = validator_getline();
		if (!buffer)
			continue;
		pointer = _memory(buffer);
		command = function_strtok(buffer, pointer);
		exit1(buffer, command);
		i = env1(buffer, command);
		if (i == 0 || command == 0)
			continue;
		function_fork(buffer, command);
	}
	return(0);
}
