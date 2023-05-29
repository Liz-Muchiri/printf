#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: the character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}

/**
 * _printf - prints formatted output to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
 */
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
