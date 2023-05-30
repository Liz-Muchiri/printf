#include "main.h"
/**
 * _printf - prints acording to a format
 * @format: character string
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count = 0;
	int i = 0;

	va_list args;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{

				count++;
				write(1, &format[i], i);

			}
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			write(1, &format[i], i);
			count++;
		}
		else
		{
			write(1, &format[i], i);
			count++;
		}
		format++;
		i++;
	}

	va_end(args);

	return (count);
}
