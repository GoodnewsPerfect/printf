#include "main.h"


int printf_character(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
