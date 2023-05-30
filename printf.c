#include "main.h"

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
case '':
count += handle_print("%c", &i, args, NULL, 0, 0, 0, 0);
break;
case 's':
count += handle_print("%s", &i, args, NULL, 0, 0, 0, 0);
break;
case '%':
count += handle_print("%%", &i, args, NULL, 0, 0, 0, 0);
break;
default:
count += handle_print("%%", &i, args, NULL, 0, 0, 0, 0);
break;
}
}
else
{
count += handle_print("%c", NULL, args, &format[i], 0, 0, 0, 0);
}
}

va(args);

return (count);
}
