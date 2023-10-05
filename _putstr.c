#include "main.h"
#include <stddef.h>
/**
 * _putstr - Prints a string to stdout.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int _putstr(char *str)
{
    int printed_chars = 0;

    if (str == NULL)
        str = "(null)";

    while (*str)
    {
        _putchar(*str);
        printed_chars++;
        str++;
    }

    return printed_chars;
}

