#include "main.h"

/**
 *print_exclusive_str - prints the exclusive strings
 *
 *@val: value to pass in
 *
 *Return: how many chars
 *
 */

int print_exclusive_str(va_list val)
{
	char *e;
	int x, len = 0;
	int v;

	e =va_arg(val, char);
	if (e == NULL)
		e = "(null)";
	for (i = 0; e[x] != '\0'; x++)
		if (e[x] < 32 || e[x] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len +2;
			v = e[x];
			if (v < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_5.2_upper_hex(v);/*this supporting funk
							      is very simlar to the one that
							      handles upper hex in task 3**/
		}
		else 
		{
			_putchar(e[x]);
			len++;
		}
	return (len);
}	
