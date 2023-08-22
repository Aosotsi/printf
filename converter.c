#include "main.h"

/**
 * convert - converts number and base into string
 * @number: input number
 * @base: input base
 * @use_lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */
char *convert(unsigned long int number, int base, int use_lowercase)
{
	char *representation;
	static char buffer[50];
	char *ptr;

	representation = (use_lowercase)
			 ? "0123456789abcdef"
			 : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = representation[number % base];
		number /= base;
	} while (number != 0);

	return (ptr);
}
