#include "main.h"
#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

int handle_print(const char *format, int *i, va_list list, char buffer[], int flags, int width, int precision, int size)
{
    if (format[*i] == 'c')
    {
        char c = va_arg(list, int);
        buffer[(*buff_ind)++] = c;
        if (*buff_ind == BUFF_SIZE)
            print_buffer(buffer, buff_ind);
        return 1; // Return the number of characters printed for 'c'
    }
    else if (format[*i] == 's')
    {
        char *str = va_arg(list, char *);
        if (str == NULL)
            str = "(null)";

        while (*str != '\0')
        {
            buffer[(*buff_ind)++] = *str++;
            if (*buff_ind == BUFF_SIZE)
                print_buffer(buffer, buff_ind);
        }
        return *buff_ind; // Return the number of characters printed for 's'
    }
    else if (format[*i] == '%')
    {
        buffer[(*buff_ind)++] = '%';
        if (*buff_ind == BUFF_SIZE)
            print_buffer(buffer, buff_ind);
        return 1; // Return the number of characters printed for '%'
    }

    return -1; // Return -1 if the specifier is not recognized
}

void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
        write(1, &buffer[0], *buff_ind);

    *buff_ind = 0;
}

int _printf(const char *format, ...)
{
    int i, printed = 0, printed_chars = 0;
    int flags, width, precision, size, buff_ind = 0;
    va_list list;
    char buffer[BUFF_SIZE];

    if (format == NULL)
        return (-1);

    va_start(list, format);

    for (i = 0; format && format[i] != '\0'; i++)
    {
        if (format[i] != '%')
        {
            buffer[buff_ind++] = format[i];
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            printed_chars++;
        }
        else
        {
            print_buffer(buffer, &buff_ind);
            flags = 0; // Assuming no flags for simplicity
            width = 0; // Assuming no width for simplicity
            precision = 0; // Assuming no precision for simplicity
            size = 0; // Assuming no size for simplicity
            ++i;
            printed = handle_print(format, &i, list, buffer, flags, width, precision, size);
            if (printed == -1)
                return (-1);
            printed_chars += printed;
        }
    }

    print_buffer(buffer, &buff_ind);

    va_end(list);

    return (printed_chars);
}

