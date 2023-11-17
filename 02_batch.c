#include "main.h"

/**
 * printpointer - this function Prints value pointer variable
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
int printpointer(va_list tp, char bf[],
	int fl, int wd, int pr, int sz)
{
	char extra_c = 0, pad = ' ';
	int index = BUFFSIZE - 2, leng = 2, padst = 1;

	unsigned long num_addrs;

	char mpt[] = "0123456789abcdef";

	void *addrs = va_arg(tp, void *);

	UNUSED(wd), UNUSED(sz);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	bf[BUFFSIZE - 1] = '\0';
	UNUSED(pr);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		bf[index--] = mpt[num_addrs % 16];
		num_addrs /= 16;
		leng++;
	}

	if ((fl & FZERO) && !(fl & FMINUS))
		pad = '0';
	if (fl & FPLUS)
		extra_c = '+', leng++;
	else if (fl & FSPACE)
		extra_c = ' ', leng++;

	index++;

	return (pointerwrite(bf, index, leng,
		wd, fl, pad, extra_c, padst));
}

/**
 * printnonprintable - Prints ascii codes in hexa of non printable chars
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
int printnonprintable(va_list tp, char bf[],
		int fl, int wd, int pr, int sz)
{
	int i = 0, offset = 0;
	char *str = va_arg(tp, char *);

	UNUSED(fl), UNUSED(wd), UNUSED(pr), UNUSED(sz);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (canweprint(str[i]))
			bf[i + offset] = str[i];
		else
			offset += apphex(str[i], bf, i + offset);

		i++;
	}

	bf[i + offset] = '\0';

	return (write(1, bf, i + offset));
}

/**
 * printinreverse - Prints reverse string.
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
int printinreverse(va_list tp, char bf[], int fl,
		int wd, int pr, int sz)
{
	char *str;
	int i, count = 0;

	UNUSED(bf);
	UNUSED(fl);
	UNUSED(wd);
	UNUSED(sz);

	str = va_arg(tp, char *);

	if (str == NULL)
	{
		UNUSED(pr);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)


	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * printrot13 - Print a string in rot13.
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
int printrot13(va_list tp, char bf[],
		int fl, int wd, int pr, int sz)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(tp, char *);
	UNUSED(bf), UNUSED(fl), UNUSED(wd), UNUSED(pr), UNUSED(sz);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
