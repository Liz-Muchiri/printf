#include "main.h"
/**
 * _printf - prints acording to a format
 * @format: character string
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				count++;
				putchar(num);

			}
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			putchar('%');
			count++;
			format++;
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
