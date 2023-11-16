
#include "main.h"

/**
 * fetchflags - this guy can calculate the number of useful flags
 *
 * @format: this guy is the preperd up string.
 *
 * @i: placeholder
 *
 * Return: fl:
 */
int fetchflags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int fl = 0;
	const char FLC[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAR[] = {FMINUS, FPLUS, FZERO, FHASH, FSPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLC[j] != '\0'; j++)
			if (format[curr_i] == FLC[j])
			{
				fl |= FLAR[j];
				break;
			}

		if (FLC[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (fl);
}

