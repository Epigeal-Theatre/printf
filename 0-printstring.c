#include "main.h"

/**
 *printstring - print a string to standard output
 *
 *@val: argument to pass in
 *
 * Return: return string length
 */


int printstring(va_list val)
{
	int length, x;
	char *str;

	str  = va_arg(val, char *);
	if (str == NULL)
	{
	str = (null);
	length = _strlen(str);
	for (x = 0; x < length; x ++)
		_putchar(str[x]);
	return (length;
	}
	else
	{
	lenght = _strlen(str);
	for (x = 0;x < length; x ++)
		_putchar(str[x]);
	return (length);
	}

}
