#include "main.h"

/**
 *print_exclusive_str - prints the exclusive strings
 *
 *@value: value to pass in
 *
 *Return: the number of chars
 *
 */

int print_exclusive_str(va_list value)
{
	char *e;
	int x, len = 0;
	int v;

	e =va_arg(value, char);
	if (e == NULL)
		E = "(null)";
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
			len = len + print_5.2_upper_hex(v);//some func from task 3 needs to be here//
		}
		else 
		{
			_putchar(e[x]);
			len++;
		}
}	
