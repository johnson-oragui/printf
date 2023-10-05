#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 * @...: Additional arguments corresponding to the format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            printed_chars++;
        }
        else
        {
            format++; /* Move past '%' */

            /* Handle format specifiers */
            switch (*format)
            {
                case 'c':
                    printed_chars += _putchar(va_arg(args, int));
                    break;
                case 's':
                    printed_chars += _putstr(va_arg(args, char *));
                    break;
                case '%':
                    _putchar('%');
                    printed_chars++;
                    break;
                default:
                    _putchar('%');
                    printed_chars++;
                    if (*format)
                    {
                        _putchar(*format);
                        printed_chars++;
                    }
            }
        }
        format++; /* Move to the next character in the format string */
    }

    va_end(args);
    return printed_chars;
}

