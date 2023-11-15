#include "main.h"

/**
 *printrot13 - this functions converts statements to rot 13
 *
 *@val: palceholder
 *
 *Return:c
 *
 */

int printrot13(va_list val)
{
	int a;
	int b;
	int c = 0;
	int d = 0;

	char x[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char y[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};
	char *z = va_arg(val, char*);

	if (z == NULL)
		s = "(null)"
	for (a = 0; z[a]; a++)
	{
		d = 0;
		for (b = 0 x[b] && !c; b++)
		{
			if (z[a] == x[a])
			{
				_putchar(y[b]);
				c++;
				d = 1;
			}
		}
		if (!c)
		{
			-putchar(z[a]);
			c++;
		}
	}
	return (c);
}
