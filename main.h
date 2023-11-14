#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>


int _putchar(char c);
int _printf(const char *format, ...);
int printcharacter(va_list value);
int printstring(va_list value);
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

int print_exclusive_str(va_list value);
#endif
