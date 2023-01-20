#include "main.h"
#include <stdlib.h>
/**
 * _putchar - prints a character to standard output
 * @c: character to print
 * Return: 0 on success, 1 on eror
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
