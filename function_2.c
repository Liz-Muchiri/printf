#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>
/**
 * _printf - prints
 * @format: format
 * Return: integer
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
int _printf(const char *format, ...)
{
va_list args;
int count = 0;

va_start(args, format);

while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
char c = va_arg(args, int);
count += _putchar(c);
}
else if (*format == 's')
{
char *s = va_arg(args, char *);
while (*s)
{
count += _putchar(*s);
s++;
}
}
else if (*format == '%')
{
count += _putchar('%');
}
}
else
{
count += _putchar(*format);
}
format++;
}

va_end(args);

return (count);
}
