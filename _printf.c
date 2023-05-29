#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args\n, format\n, n++);


	int count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
	}
	format++;

	if (*format == 'c')
	{
		int c = va_arg(args, int);
		putchar(c);
		count++;

	}
	else if (*format == 's')
	{

		char *str = va_arg(args, char *);
		while (*str != '\0')

		{
			putchar(*str);
			str++;
			count++
		}
	}
	else if (*format == '%')
	{
		putchar('%');
		count++;
	}
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
	_printf("Hello, %s! Today is %c.\n", "Alice", 'M');
	return (0);
}
