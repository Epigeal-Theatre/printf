#include "main.h"

/**
 *print_HEXADECIMAL - handles X by converting to hexadecimal caps
 *
 *@val: placeholder for value
 *
 *Return: ctr
 *
 */


int print_HEXADECIMAL(va_list val)
{
        int x;
        int ctr;
        int *arr;

        ctr = 0;

        unsigned int mynum = va-arg(val, unsigned int);

        unsigned int tempo = mynum;

        while (mynum / 16 != 0)
        {       mynum = mynum / 16;
                ctr++;
        }
        ctr++;
        arr = malloc(sizeof(int) * ctr);
        for (x = 0; x < ctr; x++)
        {       arr[x] = tempo % 16;
                tempo = tempo / 16;
        }
        for (x = ctr - 1; x >= 0; x--)
        {
                if (arr[x] > 0)
                        arr[x] = arr[x] + 7;
                _putchar(arr[x] + '0')
        }
        free(array);
        return (ctr);
}
