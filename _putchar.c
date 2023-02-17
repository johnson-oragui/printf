#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to write
 * Return: on success 0, 1 on error. 
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
