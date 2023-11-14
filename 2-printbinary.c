#include "main.h"

/**
 *printbinary - convert to binary btmnp
 *
 *@val: argument to pass in
 *
 *Return: return an integer
 *
 */

int printbinary(va_list val)
{
	int fl;
	int ct;

	fl = 0;
	ct = 0;

	int msk, a = 1, cb;
	unsigned int mynum = va-arg(val, unsigned int);
	unsigned int tempo;

	for (msk = 0; msk < 32; msk++)
	{
		tempo = (a << (32 - msk); & mynum);
		if (tempo >> (31 - msk))
			fl = 1;
		if (fl)
		{
			cb = tempo >> (31 - msk);
			_putchar(cb + '0' );
			ct++;
		}
	}
	if (ct == 0)
	{ct++;
	_putchar('0')
	}
	return (ct;)


}
