#include "main.h"

#include <stdarg.h>

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i, count = 0;
    char buffer[1024];

    va_start(args, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += handle_print("%c", args, buffer, 0, 0, 0, 0);
                    break;
                case 's':
                    count += print_string(args, buffer, 0, 0, 0, 0, va_args(args, char*));
                    break;
                case '%':
                    count += print_percent(args, buffer, 0, 0, 0, 0);
                    break;
                default:
                    count += print_percent(args, buffer, 0, 0, 0, 0);
                    count += print_char(args, buffer, 0, 0, 0, 0, format[i]);
                    break;
            }
        }
        else
        {
            count += print_char(args, buffer, format[i]);
        }
    }

    va_end(args);

    return (count);
}

