#include "main.h"

/**
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

int print_pointers(va_list value)
{
	char *y;
	void *x;
	int z;

	long int i;

	x = va-arg(value, void *);
	if (x == NULL)
	{
		for (z = 0; y[z] != '\0'; z++)
			_putchar(s[z]);
		return (z);
	}

	i = (unsigned long int)x;
	_putchar('0');
	_putchar('x');
	//ADD IN THE FUNC FOR FILE_5.2 AND PASS IN i as the argument
}
