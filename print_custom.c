#include "main.h"

/**
 * print_customS - Non printable characters
 * (0 < ASCII value < 32 or >= 127) are
 * printed this way: \x, followed by the ASCII code
 * value in hexadecimal (upper case - always 2 characters)
 * @args_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_customS(va_list args_list, flags_t *format_flags)
{
	int i, count = 0;
	char *res;
	char *input_str = va_arg(args_list, char *);

	(void)format_flags;
	if (!input_str)
		return (_puts("(null)"));

	for (i = 0; input_str[i]; i++)
	{
		if (input_str[i] > 0 && (input_str[i] < 32 || input_str[i] >= 127))
		{
			_puts("\\x");
			count += 2;
			res = convert_to_string(input_str[i], 16, 0);
			if (!res[1])
				count += _putchar('0');
			count += _puts(res);
		}
		else
			count += _putchar(input_str[i]);
	}
	return (count);
}

/**
 * print_reverse - prints a string in reverse
 * @args_list: argument from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_reverse(va_list args_list, flags_t *format_flags)
{
	int i = 0, j;
	char *input_str = va_arg(args_list, char *);

	(void)format_flags;
	if (!input_str)
		input_str = "(null)";

	while (input_str[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(input_str[j]);

	return (i);
}

/**
 * print_rot13_custom - prints a string using rot13
 * @args_list: list of arguments from _printf
 * @format_flags: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: length of the printed string
 */
int print_rot13_custom(va_list args_list, flags_t *format_flags)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *input_str = va_arg(args_list, char *);

	(void)format_flags;
	for (j = 0; input_str[j]; j++)
	{
		if (input_str[j] < 'A' || (input_str[j] > 'Z' && input_str[j] < 'a') || input_str[j] > 'z')
			_putchar(input_str[j]);
		else
		{
			for (i = 0; i <= 52; i++)
			{
				if (input_str[j] == rot13[i])
					_putchar(ROT13[i]);
			}
		}
	}

	return (j);
}

/**
 * print_customPercent - prints a percent
 * @args_list: va_list arguments from _printf
 * @format_flags: pointer to the struct flags in which we turn the flags on
 * Return: number of char printed
 */
int print_customPercent(va_list args_list, flags_t *format_flags)
{
	(void)args_list;
	(void)format_flags;
	return (_putchar('%'));
}

