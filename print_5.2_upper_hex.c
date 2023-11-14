#include "main.h"

/**
 *print_5.2_upper_hex - handles hex for funk T5
 *...as a secondary funk
 *
 *@mynum: placeholder
 *
 *Return: ctr
 *
 */

int print_5.2_upper_hex(unsigned int mynum)
{
        int x;
        int ctr;
        int *arr;

        ctr = 0;


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

