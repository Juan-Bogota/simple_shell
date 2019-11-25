#include "MyShell.h"


char  *get_path(char *command)
{
  int i;
  char delim[2]= ":=", *tokens, **token, *buffer;
  char *temp;
   i = 0;

  buffer = _getenv("PATH");

  token = malloc(sizeof(char) * 1024);
  if(token == NULL)
    {
      perror("error allocated memory");
      return(NULL);
    }
   tokens = strtok(buffer, delim);
   i = 0;
   while (tokens)
	{
	  token[i] = tokens;
	  tokens = strtok(NULL, delim);
	  i++;
	}
      token[i] = NULL;
  i = 0;
  temp = malloc(100);
  if (temp == NULL)
    return (NULL);

  while (token[i])
    {
      DIR *d;
      struct dirent *dir;
      d = opendir(token[i]);
      if (d)
	{
	  while ((dir = readdir(d)) != NULL)
	    {
	      if((strcmp(dir->d_name, command)) == 0)
		{
		  strcpy(temp, token[i]);
		  strcat(temp, "/");
		  strcat(temp, dir->d_name);
		  closedir(d);
		  return(temp);
		}
	    }
	  closedir(d);
	  i++;
	}
    }
  temp = command;
  return(temp);
}


char *_getenv(char *s)
{
	int i;
	char *find_path = NULL;
	char *final_path = NULL;
	char *copy_env;

	i = 0;
	while (environ[i] != NULL)
	{
		copy_env = _strdup(environ[i]);
		if (copy_env == NULL)
		{
			free(copy_env);
			return (NULL);
		}
		find_path = strtok(copy_env, "=");
		if (_strcmp(find_path, s) == 0)
		{
		  final_path = strstr(environ[i], "/");
		}
		i++;
	}
	free(copy_env);
	return (final_path);
}
