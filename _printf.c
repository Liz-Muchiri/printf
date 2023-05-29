#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    int count = 0;  // To keep track of the number of characters printed
    
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;  // Move past the '%'
            
            if (*format == 'c')
            {
                // Handle %c specifier
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                // Handle %s specifier
                char *str = va_arg(args, char *);
                while (*str != '\0')
                {
                    putchar(*str);
                    str++;
                    count++;
                }
            }
            else if (*format == '%')
            {
                // Handle %% specifier (print '%')
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
    
    return count;
}

int main()
{
    _printf("Hello, %s! Today is %c.\n", "Alice", 'M');
    return 0;
}
