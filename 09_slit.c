#include "main.h"

/**
 * canweprint - Evaluates if a char is printable
 *
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int canweprint(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * apphex - Append ascci in hexadecimal code to buffer
 * @bf: arr placeholder
 * @i: start of index placeholder
 * @asc: this is the ASSCI CODE
 * Return:  3
 */
int apphex(char asc, char bf[], int i)
{
	char mpt[] = "0123456789ABCDEF";

	if (asc < 0)
		asc *= -1;

	bf[i++] = '\\';
	bf[i++] = 'x';

	bf[i++] = mpt[asc / 16];
	bf[i] = mpt[asc % 16];

	return (3);
}

/**
 * dowehavedigit - this func checks if char is a digit
 *
 * @c: char placeholder
 *
 * Return: return 1 if c is digit and 0 if not digit
 */
int dowehavedigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convertsznumber - Casts a number to the specified size
 *
 * @num: cast this number
 *
 * @sz: Number indicating the type to be casted.
 *
 * Return: cast value
 */
long int convertsznumber(long int num, int sz)
{
	if (sz == SLONG)
		return (num);
	else if (sz == SSHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * unsignedszconvert - this function converts to req size
 *
 * @num: cast this num
 *
 * @sz: no size placeholder
 *
 * Return: cast value
 */
long int unsignedszconvert(unsigned long int num, int sz)
{
	if (sz == SLONG)
		return (num);
	else if (sz == SSHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

