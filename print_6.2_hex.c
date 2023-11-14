#include "main.h"

/**
 *print_6.2_hex - supports handler for pointer funk by
 *...converting return val to hex
 *
 *@mynum: placeholder
 *
 *Return: ctr
 *
 */

int print_6.2_hex(unsigned long int mynum)
	
{
        long int x;
        long int ctr;
        long int *arr;

        ctr = 0;


        unsigned long int tempo = mynum;

        while (mynum / 16 != 0)
        {       mynum = mynum / 16;
                ctr++;
        }
        ctr++;
        arr = malloc(sizeof(long int) * ctr);
        for (x = 0; x < ctr; x++)
        {       arr[x] = tempo % 16;
                tempo = tempo / 16;
        }
        for (x = ctr - 1; x >= 0; x--)
        {
                if (arr[x] > 0)
                        arr[x] = arr[x] + 39;
                _putchar(arr[x] + '0')
        }
        free(array);
        return (ctr);
}
