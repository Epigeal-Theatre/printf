#include "main.h"



/**
 * printcharacter - Prints character
 *
 * @tp: this guy is thearmuments palceholder
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
int printcharacter(va_list tp, char bf[], int fl, int wd, int pr, int sz)
{
	char c = va_arg(tp, int);


	return (writehandle_char(c, bf, fl, wd, pr, sz));
}

/**
 * printstring - Prints  strings
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
int printstring(va_list tp, char bf[], int fl, int wd, int pr, int sz)
{
	int leng = 0;
	int i;
	char *str = va_arg(tp, char *);

	UNUSED(bf), UNUSED(fl), UNUSED(wd), UNUSED(pr), UNUSED(sz);

	if (str == NULL)
	{
		str = "(null)";
		if (pr >= 6)
			str = "      ";
	}

	while (str[leng] != '\0')
		leng++;

	if (pr >= 0 && pr < leng)
		leng = pr;

	if (wd > leng)
	{
		if (fl & FMINUS)
		{
			write(1, &str[0], leng);
			for (i = wd - leng; i > 0; i--)
				write(1, " ", 1);
			return (wd);
		}
		else
		{
			for (i = wd - leng; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], leng);
			return (wd);
		}
	}

	return (write(1, str, leng));
}
/**
 * printpercent - Prints a percent sign
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
int printpercent(va_list tp, char bf[],
	int fl, int wd, int pr, int sz)
{
	UNUSED(bf), UNUSED(fl), UNUSED(wd), UNUSED(pr), UNUSED(sz);
	return (write(1, "%%", 1));
}

/**
 * printint - Prints integer
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
int printint(va_list tp, char bf[],
	int fl, int wd, int pr, int sz)
{
	int i = BUFFSIZE - 2;
	int is_negative = 0;
	long int n = va_arg(tp, long int);
	unsigned long int num;

	n = convert_sznumber(n, sz);

	if (n == 0)
		bf[i--] = '0';

	bf[BUFFSIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		bf[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (numberwriter(is_negative, i, bf, fl, wd, pr, sz));
}
/**
 * printbinary - Prints unsigned numbers
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
int printbinary(va_list tp, char bf[],
		int fl, int wd, int pr, int sz)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(bf), UNUSED(fl), UNUSED(wd), UNUSED(pr), UNUSED(sz);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

