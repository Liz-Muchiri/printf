#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "m2.h"
/**
 * _printf - prints format c and s
 * @format: character string
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	char ch, *str;
	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%' &&  format[i + 1] == 'c')
		{
			i++;
			ch = va_arg(args, int);
			write(1, &ch, 1);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			write(1, "%", 1);
			count++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			str = va_arg(args, char*);
			while (str[i] != '\0')
			{
				write(1, &str[i], 1);
				i++;
			}
			count++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
