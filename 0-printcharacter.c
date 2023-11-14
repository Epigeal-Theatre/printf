#include "main.h"

/**
 *printcharacter - prints a character char
 *
 *@value: arguments to pass in
 *
 *Return: 1
 *
 */

int printcharacter(va_list value)
{
	char str;

	str = va_arg(value, int);
	_putchar(str);
	return (1);
}
