#include "main.h"
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_str1}, {"%c", printf_character},
		{"%%", printf_num37},
		{"%i", printf_integer}, {"%d", printf_dec}, {"%r", printf_srv},
		{"%R", printf_13}, {"%b", printf_binary}, {"%u", printf_uns},
		{"%o", printf_o}, {"%x", printf_hexadecimal}, {"%X", printf_HEXADECIMAL},
		{"%S", printf_exstr}, {"%p", printf_po}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
