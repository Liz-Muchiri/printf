#include "holberton.h"
#include <stdarg.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_unsigned - prints an unsigned integer
 * @args: arguments list
 *
 * Return: number of printed characters
 */
int print_unsigned(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int divisor = 1, i, res = 0;

    while (n / divisor > 9)
        divisor *= 10;

    for (i = divisor; i >= 1; i /= 10)
    {
        res += _putchar((n / i) % 10 + '0');
    }

    return (res);
}

/**
 * print_octal - prints an octal number
 * @args: arguments list
 *
 * Return: number of printed characters
 */
int print_octal(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int octal_num[100], i = 1, j;
    int res = 0;

    while (n != 0)
    {
        octal_num[i++] = n % 8;
        n /= 8;
    }

    for (j = i - 1; j > 0; j--)
    {
        res += _putchar(octal_num[j] + '0');
    }

    return (res);
}

/**
 * print_hex - prints a hexadecimal number
 * @args: arguments list
 * @uppercase: flag to print uppercase letters
 *
 * Return: number of printed characters
 */
int print_hex(va_list args, int uppercase)
{
    unsigned int n = va_arg(args, unsigned int);
    char hex_num[100];
    int i = 0, j, res = 0;

    while (n != 0)
    {
        int temp = 0;
        temp = n % 16;
        if (temp < 10)
            hex_num[i] = temp + 48;
        else
            hex_num[i] = temp + 55 + uppercase;
        i++;
        n /= 16;
    }

    for (j = i - 1; j >= 0; j--)
    {
        res += _putchar(hex_num[j]);
    }

    return (res);
}

/**
 * _printf - prints a formatted string
 * @format: format string
 *
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, res = 0;

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'u':
                    res += print_unsigned(args);
                    break;
                case 'o':
                    res += print_octal(args);
                    break;
                case 'x':
                    res += print_hex(args, 0);
                    break;
                case 'X':
                    res += print_hex(args, 1);
                    break;
                default:
                    res += _putchar('%');
                    res += _putchar(format[i]);
                    break;
            }
        }
        else
        {
            res += _putchar(format[i]);
        }
        i++;
    }

    va_end(args);

    return (res);
}
