#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>





typedef struct format
{
	char *id;
	int (*f)();
} convert_match;

int printf_po(va_list val);
int printf_hexadecimal_aux(unsigned long int num);
int printf_HEXADECIMAL_X(unsigned int num);
int printf_exstr(va_list val);
int printf_HEXADECIMAL(va_list val);
int printf_hexadecimal(va_list val);
int printf_o(va_list val);
int printf_uns(va_list args);
int printf_binary(va_list val);
int printf_srv(va_list args);
int printf_13(va_list args);
int printf_integer(va_list args);
int printf_dec(va_list args);
int _strlen(char *s);
int *_strcpy(char *dest, char *src);
int _strlenc(const char *s);
int rev_string(char *s);
int _strlenc(const char *s);
int printf_num37(void);
int printf_character(va_list val);
int printf_str1(va_list val);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
