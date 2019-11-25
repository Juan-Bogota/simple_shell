#include "MyShell.h"
/**
 * *_strcpy 
 */

char *_strcpy(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (src[a] != '\0')
	{
		dest[b] = src[a];
		a++;
		b++;
	}
	return (dest);
}

/**
 * _strdup - function will return pointer to copied string
 */

char *_strdup(char *str)
{
	char *ptr;

	if (str == NULL)
		return (NULL);
	ptr = malloc(_strlen(str) + 1);
	if (ptr != NULL)
		_strcpy(ptr, str);
	return (ptr);
}

/**
 * *_strcat - Function will concatenate two strings
 */
char *_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	b = 0;

	while (dest[b] != '\0')
	{
		b++;
	}
	while (src[a] != '\0')
	{
		dest[b] = src[a];
		a++;
		b++;
	}
	dest[b] = '\0';
	return (dest);
}

/**
 */

int _strlen(char *s)
{
	int length;

	length = 0;
	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}

/**
 */

int _strcmp(char *s1, char *s2)
{
	int a;

	a = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] < s2[a] || s1[a] > s2[a])
			return (s1[a] - s2[a]);
		a++;
	}
	return (0);
}
