#include "main.h"

/**
 * fetchwidth - this function calculates width
 *
 * @format: preped up string
 *
 * @i: placeholder
 *
 * @list: placeholder
 *
 * Return: wd.
 */
int fetchwidth(const char *format, int *i, va_list list)
{
	int curr_i;
	int wd = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (dowehavedigit(format[curr_i]))
		{
			wd *= 10;
			wd += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			wd = va_arg(list, int);
			break;
		}

		else
			break;
	}

	*i = curr_i - 1;

	return (wd);
}

