#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);
				count += printf("%d", num);
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

int main(void)
{
	_printf("The number is %d.\n", 42);
	return (0);
}

