#include "main.h"

/**
 *print_reversedstring - this function prints a given
 *...string in reverse
 *
 *@val: palaceholder
 *
 *Return: ystr
 *
 */

int print_reversedstring(va_list val)
{
	int x;
	int y;
	char *Z = va_arg(val, char*);

	y = 0;

	if (z == NULL)
	Z == "(null)";
	while (z[y] != '\0')
	y++;
	for (x = y - 1; x >= 0; x--)
	_putchar(z[x]);
	return (y);

}
