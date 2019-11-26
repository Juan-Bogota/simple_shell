#include "MyShell.h"

/**
 * _strstr - searches a string for any of a set of bytes
 * @haystack: first occurrence of the character
 * @needle: array string
 *Return: Always 0.
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;
	int k;
	for (i = 0; haystack[i] != '\0'; i++)
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && needle[j] != '\0')
		{
			j++;
			k++;
		}
		if (needle[j] == '\0')
		{
			return (haystack + i);
		}
	}
	return (0);
}
