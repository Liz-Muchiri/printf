#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "m2.h"
/**
 * _print - prints specifiers d and i
 * @format: specifier string
 * Return: count
 */
int _putchar(char a);
int _print(const char *format, ...)
{
	int i, count;
	long int num;
	va_list numbers;

	va_start(numbers, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				num = va_arg(numbers, int);
				if (num < 0)
				{
					_putchar(num * (-1));
					count++;
				}
				else if (num > 99)
				{
					_putchar((num / 100) + '0');
					_putchar(((num / 10) % 10) + '0');
					_putchar((num % 10) + '0');
					count++;
				}
				else if (num > 9)
				{
					_putchar((num / 10) + '0');
					_putchar((num % 10) + '0');
					count++;
				}
				else
				{
					_putchar((num % 10) + '0');
					count++;
				}
			}
			else
			{
				write(1, &format[i], 1);
				count++;
			}
		}
	}
	return (count);
}
/**
 * _putchar - prints a character
 * @a: character to be peinted
 * Return: integer
 */
int _putchar(char a)
{
	return(write(1, &a, 1));
}
