#include "main.h"

/**
 *printcharacter - prints a character char
 *
 *@val: arguments to pass in
 *
 *Return: 1
 *
 */

int printcharacter(va_list val)
{
	char str;

	str = va_arg(val, int);
	_putchar(str);
	return (1);
}
