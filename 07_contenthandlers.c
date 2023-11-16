#include "main.h"
/**
 * contenthandler - Prints an argument based on its type
 *
 * @fmt: placeholder for formated string
 *
 * @list: placeholder for arguments
 *
 * @index: placeholder
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
 * Return: 1 or 2
 */
int contenthandler(const char *fmt, int *index, va_list list, char bf[],
	int fl, int wd, int pr, int sz)
{
	int i, ukl = 0, printedch = -1;
	fmt_t fmt_types[] = {
		{'c', printcharacter}, {'s', printstring}, {'%', printpercent},
		{'i', printint}, {'d', printint}, {'b', printbinary},
		{'u', printunsigned}, {'o', printoctals}, {'x', printhexadecimals},
		{'X', printHEXADECIMAL}, {'p', printpointer}, {'S', printnonprintable},
		{'r', printinreverse}, {'R', printrot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*index] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, bf, fl, wd, pr, sz));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		ukl += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			ukl += write(1, " ", 1);
		else if (wd)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		ukl += write(1, &fmt[*index], 1);
		return (ukl);
	}
	return (printedch);
}

