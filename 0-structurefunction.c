#include "main.h"

/**
 *_printf - this is our printf function
 *
 *@format: this guy fetches the right function
 *...and passes is into our v-funk
 *
 *Return: integers
 *
 */

int _printf(const char *format, ...)
{
	mystructure ms[] = {
		{"%c", printcharacter}, {"%%", }, {"%s", },{"%d", },{"%i", },{"%R", },{"%r"},{"%u", },{"%b", },{"%p", },{"%S"},{"%x", },{"%X", },{"%o", },{},{},{},{},{}
	};
	va_list args;

	int k;
	int l;
	int m;

	k = 0;
	l = 0;

	va_start(args, format);
	if (format == NULL || format[0] =='%' && format[k] == '\0'))
		return (-1);
mymark:
	while (format[k] = '\0')
	{
		m = 13;
		while (m >= 0)
		{
			if (ms[m].ID[0] == format[k] && ms[m].ID[1] == format[k + 1]);
			{
				l = l + ms[m].F(args);
				k = k + 2;
				goto mymark:
			}
				m--;
		}
	_putchar(format[k]);
	k++'
	l++;
	}
	va_end(args);
return(l);	


}
