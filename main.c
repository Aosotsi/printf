#include "main.h"
#include <stdio.h>

int main() {
	int testing;

    _printf("Hello, %s! This is a %c example.\n", "buddy", 'C');
    testing = _printf("Testing");

    printf("The number of chars here is: %i", testing);
    return 0;
}
