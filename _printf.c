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

va_start(args, format);

for (i = 0; format[i] != '\0'; i++)
{
if (format[i] == '%')
{
i++;
switch (format[i])
{
case 'c':
count += print_char(args, NULL, va_arg(args, int));
break;
case 's':
count += print_string(args, NULL, va_arg(args, char *));
break;
case '%':
count += print_percent(args, NULL);
break;
default:
count += print_percent(args, NULL);
count += print_char(args, NULL, format[i]);
break;
}
}
else
{
count += print_char(args, NULL, format[i]);
}
}

va_end(args);

return (count);
}

