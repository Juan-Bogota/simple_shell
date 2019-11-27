#include "MyShell.h"

char **function_strtok(char *buffer, int pointer)
{
	char **command;
	size_t i;
	char *tok;
	char *delim = " \n";

	command = malloc(sizeof(char *) * pointer);
	if (command == NULL)
	{
		free(buffer);
		return (NULL);
	}
	tok = strtok(buffer, delim);
	i = 0;
	while (tok)
	{
		command[i] = tok;
		tok = strtok(NULL, delim);
		i++;
	}
	command[i] = NULL;
	return (command);
}


/**
 MEMORY POINTERS
 */
int _memory(char *buffer)
{
  int i , count = 2;
  char *delim = " ";

  for(i = 0; buffer[i] != '\0'; i++)
    {
     	  if (buffer[i] == delim[0])
	    count++;
    }
  return (count);
}

/**
 MEMORY POINTERS
 */
int _memory1(char *buffer)
{
  int i , count = 2;
  char *delim = ":";

  for(i = 0; buffer[i] != '\0'; i++)
    {
     	  if (buffer[i] == delim[0])
	    count++;
    }
  return (count);
}
