#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: the character to write
 *
 * Return: the number of characters written (1 on success, -1 on error)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - formatted output conversion
 * @format: the format string
 * ...: the variable arguments
 *
 * Return: the number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[BUFF_SIZE] = {0};
	int i = 0;

	va_start(args, format);

	while (format[i])
{
	if (format[i] == '%')
{
	i++;
	int flags = get_flags(format, &i);
	int width = get_width(format, &i, args);
	int precision = get_precision(format, &i, args);
	int size = get_size(format, &i);

count += handle_print(format, &i, args, buffer, flags, width, precision, size);
}
else
{
	count += _putchar(format[i]);
	i++;
}
}

va_end(args);
return (count);
}
