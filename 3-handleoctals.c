#include "main.h"

/**
 *printoctal - handles o by converting into octals
 *
 *@val: placeholder
 *
 *Return: return ctr
 */

int printoctal(va_list val)
{
	int x;
	int ctr;
	int *arr;

	ctr = 0;

	unsigned int mynum = va-arg(val, unsigned int);

	unsigned int tempo = mynum;

	while (mynum / 8 != 0)
	{	mynum = mynum / 8;
		ctr++;
	}
	ctr++;
	arr = malloc(sizeof(int) * ctr);
	for (x = 0; x < ctr; x++)
	{	arr[x] = tempo % 8;
		tempo = tempo / 8;
	}
	for (x = ctr - 1; x >= 0; x--)
		_putchar(arr[x] + '0');
	free(arr);
	return (ctr);


