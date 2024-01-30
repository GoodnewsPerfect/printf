#include "main.h"


int printf_hexadecimal_aux(unsigned long int num)
{
	long int i;
	long int *array;
	long int c = 0;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		c++;
	}
	c++;
	array = malloc(c * sizeof(long int));

	for (i = 0; i < c; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = c - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 39;
		_putchar(array[i] + '0');
	}
	free(array);
	return (c);
}
