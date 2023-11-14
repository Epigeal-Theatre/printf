#include "main.h"

/**
 *printstring - print a string to standard output
 *
 *@value: argument to pass in
 *
 * Return: return string length
 */


int printstring(va_list value)
{
	int length, x;
	char *str;

	str  = va_arg(value, char *);
	if (str == NULL)
	{
	str = (null);
	length = _strlen(str);
	for (x = 0; x < length; x ++)
		_putchar(str[x]);
	return (lengthg);
	}
	else
	{
	lenght = _strlen(str);
	for (x = 0;x < length; x ++)
		_putchar(str[x]);
	return (length);
	}

}
