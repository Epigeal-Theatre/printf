#include "main.h"

/**
 *print_integer_i -prints integer i
 *
 *@args arguments placeholder
 *
 *Return: characters to print
 *
 */

int handleunsigned_u(va_list args)
{
        int x = va_arg(args, int);

        int i;

        i = 1;

        int myNum, last = x % 10, digit, exp = 1;

        x = x / 10;
        myNum = x;

        if (last < 0)
        {
                _putchar('-');
        myNum = -myNum;
        x = -x;
        last = -last;
        x++;
        }
        if (myNum > 0)

        {       while (myNum / 10 != 0)
                {
                exp = exp *10;
                myNum = myNum /10
                }
        myNum = x;
        while (exp > 0)
        {       digit = myNum / exp;
        _putchar(digit + '0');
        myNum = myNum  - (digit * exp);
        exp = exp / 10;
        x++;
        }
        }
        _putchar(last + '0');
        return (1);


}
