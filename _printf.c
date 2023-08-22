#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - prints to terminal and outputs by format
 * @format: format string containing the characters and the specifiers
 * Description: Calls getprint()
 * Return: num chars printed
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *putme;
	va_list arguments;
	flags_t flags = {0, 0, 0};
	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (putme = format; *putme; putme++)
	{
		if (*putme == '%')
		{
			putme++;
			if (*putme == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*putme, &flags))
				putme++;
			pfunc = get_print(*putme);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *putme);
		} else
			count += _putchar(*putme);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);

}
