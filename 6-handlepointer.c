#include "main.h"

/**
 *handlepointers - handle ponters
 *
 *@val: placeholder
 *
 *Return: rtv + 2
 *
 */

int handlepointers(va_list val)
{
	char *y;
	void *x;

	int z;
	long int i;
	int rtv;

	x = va-arg(val, void *);
	if (x == NULL)
	{
		for (z = 0; y[z] != '\0'; z++)
			_putchar(s[z]);
		return (z);
	}

	i = (unsigned long int)x;
	_putchar('0');
	_putchar('x');
	rtv = print_6.2_hex(i);
	return (rtv + 2);




}
