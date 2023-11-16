#include "main.h"

void print_buffer(char bf[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printedch = 0;
	int fl, wd, pr, sz, buff_ind = 0;
	va_list list;
	char bf[BUFFSIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			bf[buff_ind++] = format[i];
			if (buff_ind == BUFFSIZE)
				print_buffer(bf, &buff_ind);
			/* write(1, &format[i], 1);*/
			printedch++;
		}
		else
		{
			print_buffer(bf, &buff_ind);
			fl = fetchflagslags(format, &i);
			wd = fetchwidth(format, &i, list);
			pr = fetchprecision(format, &i, list);
			sz = fetchsize(format, &i);
			++i;
			printed = contenthandler(format, &i, list, bf,/*contenthandler*/
				fl, wd, pr, sz);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(bf, &buff_ind);

	va_end(list);

	return (printedch);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @bf: placeholder for arrays
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char bf[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &bf[0], *buff_ind);

	*buff_ind = 0;
}

