#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "m2.h"
#define BUFFER 1024
void print_buffer(char b[], int *b_ind);
/**
 * _printf - prints format c and s
 * @format: character string
 * Return: integer
 */
int _printf(const char *format, ...)
{
	int i, count = 0, b_ind = 0;
	char ch, *string, b[BUFFER];
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
				string = "(null)";
			while (*string)
			{
				b[b_ind++] = *string;
				if (b_ind <= BUFFER)
					print_buffer(b, &b_ind);
				string++;
				count++;
			}
		}
		else
		{
			if (format[i] == '%' && format[i + 1] == '\0')
				return (-1);
			b[b_ind++] = format[i];
			if (b_ind <= BUFFER)
				print_buffer(b, &b_ind);
			count++;

		}
	}
	return (count);
}

/**
 * print_buffer - prints with description
 * @b: array
 * @b_ind: buffer index
 */
void print_buffer(char b[], int *b_ind)
{
	if (*b_ind > 0)
		write(1, &b[0], *b_ind);
	*b_ind = 0;
}
