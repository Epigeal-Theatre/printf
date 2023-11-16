#include "main.h"

/**
 * writehandle_char - this function prints strs
 * @c: placeholder
 * @bf: placeholder for buffer arr
 * @fl:  this guy takes care of flags
 * @wd: this guy takes care of width
 * @pr: this guy takes care of precision
 * @sz: this guy takes care of size
 * Return: how many chars did we print?
 */
int writehandle_char(char c, char bf[],
		int fl, int wd, int pr, int sz)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char pad = ' ';

	UNUSED(pr), UNUSED(sz);

	if (fl & FZERO)
		pad = '0';

	bf[i++] = c;
	bf[i] = '\0';

	if (wd > 1)
	{
		bf[BUFFSIZE - 1] = '\0';
		for (i = 0; i < wd - 1; i++)
			bf[BUFFSIZE - i - 2] = pad;

		if (fl & FMINUS)
			return (write(1, &bf[0], 1) +
					write(1, &bf[BUFFSIZE - i - 1], wd - 1));
		else
			return (write(1, &bf[BUFFSIZE - i - 1], wd - 1) +
					write(1, &bf[0], 1));
	}

	return (write(1, &bf[0], 1));
}

/**
 * numberwriter - this function handles numberst print
 * @is_negative: this guy checks for negative numbers
 * @index: char types.
 * @bf: placeholder for buffer arr
 * @fl:  this guy takes care of flags
 * @wd: this guy takes care of width
 * @pr: this guy takes care of precision
 * @sz: this guy takes care of size
 * Return: how many chars did we print?
 */
int numberwriter(int is_negative, int index, char bf[],
		int fl, int wd, int pr, int sz)
{
	int leng = BUFFSIZE - index - 1;
	char pad = ' ', extra_ch = 0;

	UNUSED(sz);

	if ((fl & FZERO) && !(fl & FMINUS))
		pad = '0';
	if (is_negative)
		extra_ch = '-';
	else if (fl & FPLUS)
		extra_ch = '+';
	else if (fl & FSPACE)
		extra_ch = ' ';

	return (writemynum(index, bf, fl, wd, pr,
		leng, pad, extra_ch));
}

/**
 * numwriter  - this function uses buffer to write numbers
 * @index: Index at which the number starts on the buffer
 * @bf: placeholder for bf
 * @leng: placeholder for length
 * @fl: placeholder for fl
 * @wd: placeholder for wd
 * @pre: specify the precision
 * @pad: Placeholdeer for pading
 * @extra_c: we an extra character
 * Return: how many chars did we print
 */
int numwriter(int index, char bf[], int fl, int wd,
		int pre, int leng, char pad, char extra_c)
{
	int i, padst = 1;

	if (pre == 0 && index == BUFFSIZE - 2 && bf[index] == '0' && wd == 0)
		return (0);
	if (pre == 0 && index == BUFFSIZE - 2 && bf[index] == '0')
		bf[index] = pad = ' ';
	if (pre > 0 && pre < leng)
		pad = ' ';
	while (pre > leng)
		bf[--index] = '0', leng++;
	if (extra_c != 0)
		leng++;
	if (wd > leng)
	{
		for (i = 1; i < wd - leng + 1; i++)
			bf[i] = pad;
		bf[i] = '\0';
		if (fl & FMINUS && pad == ' ')
		{
			if (extra_c)
				bf[--index] = extra_c;
			return (write(1, &bf[index], leng) + write(1, &bf[1], i - 1));
		}
		else if (!(fl & FMINUS) && pad == ' ')
		{
			if (extra_c)
				bf[--index] = extra_c;
			return (write(1, &bf[1], i - 1) + write(1, &bf[index], leng));
		}
		else if (!(fl & FMINUS) && pad == '0')
		{
			if (extra_c)
				bf[--padst] = extra_c;
			return (write(1, &bf[padst], i - padst) +
				write(1, &bf[index], leng - (1 - padst)));
		}
	}
	if (extra_c)
		bf[--index] = extra_c;
	return (write(1, &bf[index], leng));
}

/**
 * unsignedwriter - this function will write unsigned numbers
 * @is_negative: is the number negative?
 * @bf: placeholder for buffer arr
 * @fl:  this guy takes care of fl
 * @index: placeholder for index
 * @wd: this guy takes care of wd
 * @pr: this guy takes care of pr
 * @sz: this guy takes care of sz
 * Return: how many chars did we print?
 */
int unsignedwriter(int is_negative,
		int index, char bf[], int fl, int wd, int pr, int sz)
{
	int leng = BUFFSIZE - index - 1, i = 0;
	char pad = ' ';

	UNUSED(is_negative), UNUSED(sz);

	if (pr == 0 && index == BUFFSIZE - 2 && bf[index] == '0')
		return (0);

	if (pr > 0 && pr < leng)
		pad = ' ';

	while (pr > leng)
	{
		bf[--index] = '0';
		leng++;
	}

	if ((fl & FZERO) && !(fl & FMINUS))
		pad = '0';

	if (wd > leng)
	{
		for (i = 0; i < wd - leng; i++)
			bf[i] = pad;

		bf[i] = '\0';

		if (fl & FMINUS)
		{
			return (write(1, &bf[index], leng) + write(1, &bf[0], i));
		}
		else
		{
			return (write(1, &bf[0], i) + write(1, &bf[index], leng));
		}
	}

	return (write(1, &bf[index], leng));
}

/**
 * pointerwrite - this function Writes mem addres
 * @bf: placeholder
 * @index: index placeholder
 * @leng: Length of number
 * @wd: wd placeholder
 * @fl: fl placeholder
 * @pad: padding placeholder
 * @extra_c: extra char
 * @padst: where does our padding start?
 * Return: how many chars did we write
 */
int pointerwrite(char bf[], int index,
		int leng, int wd, int fl, char pad, char extra_c, int padst)
{
	int i;

	if (wd > leng)
	{
		for (i = 3; i < wd - leng + 3; i++)
			bf[i] = pad;
		bf[i] = '\0';
		if (fl & FMINUS && pad == ' ')
		{
			bf[--index] = 'x';
			bf[--index] = '0';
			if (extra_c)
				bf[--index] = extra_c;
			return (write(1, &bf[index], leng) + write(1, &bf[3], i - 3));
		}
		else if (!(fl & FMINUS) && pad == ' ')
		{
			bf[--index] = 'x';
			bf[--index] = '0';
			if (extra_c)
				bf[--index] = extra_c;
			return (write(1, &bf[3], i - 3) + write(1, &bf[index], leng));
		}
		else if (!(fl & FMINUS) && pad == '0')
		{
			if (extra_c)
				bf[--padst] = extra_c;
			bf[1] = '0';
			bf[2] = 'x';
			return (write(1, &bf[padst], i - padst) +
				write(1, &bf[index], leng - (1 - padst) - 2));
		}
	}
	bf[--index] = 'x';
	bf[--index] = '0';
	if (extra_c)
		bf[--index] = extra_c;
	return (write(1, &bf[index], BUFFSIZE - index - 1));
}

