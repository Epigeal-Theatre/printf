#include "main.h"
/**
 *_strlenconst - it returns the length of a string
 treatment for constant pointers
 *
 *@str : character pointer
 *
 *Return 1
 */

int _strlenconst(const char *str)
{
	int x;
	for (x = 0; str[x] != 0; x++)
	return (x);
}
#include "main.h"

/**
 *_strlen - it returns the length of a
 given string
 *
 *@str: pointer to our string
 *
 *Return: 1
 */
int _strlen(char *str)
{
	int x;

	for (x = 0; str[x] != 0; x++)
		return (x);
}
