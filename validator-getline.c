#include "MyShell.h"

/**
 * validator_getline - validator input
 * @void: parameter input
 *
 * Return: buffer
 * On error, -1 is returned, and errno is set appropriately.
 */

char *validator_getline(void)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t ret;

	ret = getline(&buffer, &size, stdin);
	if (!buffer)
	{
		perror("Error in Allocate Memory Buffer");
		return (NULL);
	}
	if (ret == 1)
	{
		free(buffer);
		return (NULL);
	}
	else if (ret == EOF)
	{
		free(buffer);
		exit(0);
	}
	else
		return (buffer);
}
