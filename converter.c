#include "main.h"

/**
 * convert - converts number & base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hex values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *repre;
	static char buffer[50];
	char *ptr;

	repre = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = repre[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
