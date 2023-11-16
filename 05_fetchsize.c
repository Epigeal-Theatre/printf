#include "main.h"

/**
 * fetchsize - this guy calculates size of argument before its put
 *
 * @format: preped up string
 *
 * @i: placeholder
 *
 * Return: sz.
 */
int fetchsize(const char *format, int *i)
{
	int curr_i = *i + 1;
	int sz = 0;


	if (format[curr_i] == 'l')
		sz = SLONG;
	else if (format[curr_i] == 'h')
		sz = SSHORT;

	if (sz == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (sz);
}
