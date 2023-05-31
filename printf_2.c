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
	int i, count = 0;
	char ch, *string;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
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
			i++;
			string = va_arg(args, char*);
			if (string == NULL)
			{
				string = "(null)";
			}
			while (*string)
			{
				write(1, &string[0], 1);
				string++;
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	return (count);
}
