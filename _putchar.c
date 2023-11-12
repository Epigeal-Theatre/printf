#include "main.h"

/**
 *_putchar- outputs chcharacter to the standard
 output
 *
 *@c character to print to stdout
 *
 * Return: 1 upon success
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
