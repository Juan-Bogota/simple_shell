#include "MyShell.h"
/**
 VALIDATOR _ GETLINE
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
		write(1, "\n", 1);
		exit(0);
	}
	else
	  return (buffer);
}
