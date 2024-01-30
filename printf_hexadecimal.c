#include "main.h"


int printf_hexadecimal(va_list val)
{
	int j;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (j = 0; j < counter; j++)
	{
		array[j] = temp % 16;
		temp /= 16;
	}
	for (j = counter - 1; j >= 0; j--)
	{
		if (array[j] > 9)
			array[j] = array[j] + 39;
		_putchar(array[j] + '0');
	}
	free(array);
	return (counter);
}
