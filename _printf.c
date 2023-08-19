#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

int _printf(const char *format, ...)
{
    int i;
    int count = 0;

    va_list args;

    va_start(args, format);

    for (i = 0; format[i] != '\0'; ++i) {
        if (format[i] == '%') {
            switch (format[i + 1]) {
                case 'c':
                    putchar(va_arg(args, int));
                    ++count;
                    break;
				case 's': 
				{
				    const char *str_arg = va_arg(args, const char *);
				    fputs(str_arg, stdout);
				    count += strlen(str_arg);
				    break;
				}
                case '%':
                    putchar('%');
                    ++count;
                    break;
                default:
                    break;
            }
            ++i; // Move past the conversion specifier
        } else {
            putchar(format[i]);
            ++count;
        }
    }

    va_end(args);
    return count;
}
