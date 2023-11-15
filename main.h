#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 *struct format - fetches functions for our printf
 *
 *@ID: our pinter to f
 *
 * @F: func that identifies other funcs
 */

typedef struct format
{
	int (*F)();
	char *ID;
}mystructure;


int _putchar(char c);
int _printf(const char *format, ...);
int printcharacter(va_list val);
int printstring(va_list val);
int _strlenconst(const char *str);
int _strlen(char *str);
int print_percentage37();
int print_integer_i(va_list args);
int print_decimal_d(va_list args);
int printbinary(va_list val);
int handleunsigned_u(va_list args);
int printoctal(va_list val);
int print_hexadecimal(va_list val);
int print_HEXADECIMAL(va_list val);

int print_exclusive_str(va_list val);
int print_5.2_upper_hex(unsigned int mynum);

int handlepointers(va_list val);
int print_6.2_hex(unsigned long int mynum);

int print_reversedstring(va_list val);
int printrot13(va_list val);
#endif
