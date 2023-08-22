#include "main.h"

/**
 * print_int - prints an integer
 * @args_list: va_list of arguments from _printf
 * @format_flags: pointer to the struct flags determining
 *               if a flag is passed to _printf
 * Return: number of char printed
 */
int print_int(va_list args_list, flags_t *format_flags)
{
	int number = va_arg(args_list, int);
	int result = count_digits(number);

	if (format_flags->space == 1 && format_flags->plus == 0 && number >= 0)
		result += _putchar(' ');
	if (format_flags->plus == 1 && number >= 0)
		result += _putchar('+');
	if (number <= 0)
		result++;
	print_number_recursive(number);
	return (result);
}

/**
 * print_unsigned - prints an unsigned integer
 * @args_list: va_list of arguments from _printf
 * @format_flags: pointer to the struct flags determining
 *               if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list args_list, flags_t *format_flags)
{
	unsigned int unsigned_num = va_arg(args_list, unsigned int);
	char *str_representation = convert_to_string(unsigned_num, 10, 0);

	(void)format_flags;
	return (_puts(str_representation));
}

/**
 * print_number_recursive - helper function that recursively
 * prints all digits of an integer
 * @number: integer to be printed
 */
void print_number_recursive(int number)
{
	unsigned int positive_value;

	if (number < 0)
	{
		_putchar('-');
		positive_value = -number;
	}
	else
		positive_value = number;

	if (positive_value / 10)
		print_number_recursive(positive_value / 10);
	_putchar((positive_value % 10) + '0');
}

/**
 * count_digits - returns the number of digits in an integer
 * for _printf
 * @integer: integer to evaluate
 * Return: number of digits
 */
int count_digits(int integer)
{
	unsigned int digit_count = 0;
	unsigned int abs_value;

	if (integer < 0)
		abs_value = -integer;
	else
		abs_value = integer;
	while (abs_value != 0)
	{
		abs_value /= 10;
		digit_count++;
	}
	return (digit_count);
}
