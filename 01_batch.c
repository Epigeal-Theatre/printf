#include "main.h"

/**
 * printunsigned - this function Prints unsigned numbers
 *
 * @tp: this guy is the armuments palceholder
 *
 * @bf: this guy is the printing array
 *
 * @fl: this guyells how many flags there are
 *
 * @wd: the Width of our buffer
 *
 * @pr: this guy specifies precision
 *
 * @sz: this guy specifies size
 *
 * Return: Number of chars printed.
 */
int printunsigned(va_list tp, char bf[],
		int fl, int wd, int pr, int sz)
{
	int i = BUFFSIZE - 2;
	unsigned long int num = va_arg(tp, unsigned long int);

	num = unsignedszconvert(num, sz);

	if (num == 0)
		bf[i--] = '0';

	bf[BUFFSIZE - 1] = '\0';

	while (num > 0)
	{
		bf[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (unsignedwriter(0, i, bf, fl, wd, pr, sz));
}

/**
 * printoctals - this functionPrints
 * ... unsigned numbers but in octal form
 *
 * @tp: this guy is the armuments palceholder
 *
 * @bf: this guy is the printing array
 *
 * @fl: this guyells how many flags there are
 *
 * @wd: the Width of our buffer
 *
 * @pr: this guy specifies precision
 *
 * @sz: this guy specifies size
 *
 * Return: how many chars are printed
 */
int printoctals(va_list tp, char bf[],
		int fl, int wd, int pr, int sz)
{

	int i = BUFFSIZE - 2;
	unsigned long int num = va_arg(tp, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wd);

	num = unsignedszconvert(num, sz);

	if (num == 0)
		bf[i--] = '0';

	bf[BUFFSIZE - 1] = '\0';

	while (num > 0)
	{
		bf[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (fl & FHASH && init_num != 0)
		bf[i--] = '0';

	i++;

	return (unsignedwriter(0, i, bf, fl, wd, pr, sz));
}

/**
 * printhexadecimals - this function Prints
 * ...unsigned numbers in hexadecimal form
 *
 * @tp: this guy is the armuments palceholder
 *
 * @bf: this guy is the printing array
 *
 * @fl: this guy tells how many flags there are
 *
 * @wd: the Width of our buffer
 *
 * @pr: this guy specifies precision
 *
 * @sz: this guy specifies size
 *
 * Return: how many chars are printed
 */
int printhexadecimals(va_list tp, char bf[],
		int fl, int wd, int pr, int sz)
{
	return (printhexadecimallowup(tp, "0123456789abcdef", bf,
		fl, 'x', wd, pr, sz));
}

/**
 * printHEXADECIMAL - this function Prints
 * ...unsigned numbers in HEXADECIMAL uppercase
 *
 * @tp: this guy is the armuments palceholder
 *
 * @bf: this guy is the printing array
 *
 * @fl: this guyells how many flags there are
 *
 * @wd: the Width of our buffer
 *
 * @pr: this guy specifies precision
 *
 * @sz: this guy specifies size
 *
 * Return: how many chars are printed
*/
int printHEXADECIMAL(va_list tp, char bf[],
		int fl, int wd, int pr, int sz)
{
	return (printhexadecimallowup(tp, "0123456789ABCDEF", bf,
		fl, 'X', wd, pr, sz));
}

/**
 * printhexadecimallowup - this function Prints
 * ... hexadecimal numbers in low/up
 *
 * @mpt: this guy is an arr for values towhich we map no.s
 *
 * @flc: this guy reports on flag activity
 *
 * @tp: this guy is the armuments palceholder
 *
 * @bf: this guy is the printing array
 *
 * @fl: this guyells how many flags there are
 *
 * @wd: the Width of our buffer
 *
 * @pr: this guy specifies precision
 *
 * @sz: this guy specifies size
 *
 * Return: how many chars are printed
 */
int printhexadecimallowup(va_list tp, char mpt[], char bf[],
		int fl, char flc, int wd, int pr, int sz)
{
	int i = BUFFSIZE - 2;
	unsigned long int num = va_arg(tp, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(wd);

	num = unsignedszconvert(num, sz);

	if (num == 0)
		bf[i--] = '0';

	bf[BUFFSIZE - 1] = '\0';

	while (num > 0)
	{
		bf[i--] = mpt[num % 16];
		num /= 16;
	}

	if (fl & FHASH && init_num != 0)
	{
		bf[i--] = flc;
		bf[i--] = '0';
	}

	i++;

	return (unsignedwriter(0, i, bf, fl, wd, pr, sz));
}

