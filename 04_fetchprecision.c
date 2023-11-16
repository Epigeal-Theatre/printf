#include "main.h"

/**
 * fetchprecision - this guy undestands precision before printing
 *
 * @format: this guy formats strings
 *
 * @i: placeholder
 *
 * @list: placeholder
 *
 * Return: pr
 */
int fetchprecision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int pr = -1;

	if (format[curr_i] != '.')
		return (pr);

	pr = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (dowehavedigit(format[curr_i]))
		{
			pr *= 10;
			pr += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			pr = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (pr);
}
