#include <stdio.h>
#include <stdarg.h>
#include <strings.h>
#include <limits.h>
#include "main.h"
/**
 * _printf - prints formatted text
 * @format: series of arguments
 * Return: formatted text
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i;
	unsigned int n;
	int index;

	va_start(args, format);
	for (i = 0; format[i] != '0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					printf("%s", va_arg(args, char *));
					count += strlen(var_arg(args, char));
					break;
				case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;
				case 'b':
					n = va_arg(args, unsigned int);
					char bin_str(sizeof(unsigned int) * 8 + 1);
					index = sizeof(unsigned int) * 8;
					bin_str[index] = '0';
					while (n > 0)
					{
						bin_str[--index] = (n % 2) + '0';
						n /= 2;
					}
					printf("%s", &bin_str[index]);
					count += sizeof(unsigned int) * 8 - index;
					break;
				case 'u':
					count += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					count += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					count += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					count += printf("%X", va_arg(args, unsigned int));
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar(format[i]);
					count++;
					break;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
