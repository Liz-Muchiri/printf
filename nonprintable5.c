#include "main.h"

/**
 * print_non_printable - Prints a string, replacing non-printable characters
 * with their ASCII code value in hexadecimal
 * @types: List of arguments
 * @buffer: Buffer to store output
 * @flags: Flags to modify output
 * @width: Minimum field width
 * @precision: Precision of output
 * @size: Size modifier
 *
 * Return: Number of characters printed
 */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str = va_arg(types, char *);
int i, j, count = 0;
char hex[3];

if (str == NULL)
str = "(null)";

for (i = 0; str[i] != '\0'; i++)
{
if (is_printable(str[i]))
{
count += handle_write_char(str], buffer, flags, width, precision, size);
}
else
{
count += handle_write_char('\\', buffer, flags, width, precision, size);
count += handle_write_char('x', buffer, flags, width, precision, size);
sprintf(hex, "%02X", str[i]);
for (j = 0; hex[j] != '\0'; j++)
{
count += handle_write_char(hex[j], buffer, flags, width, precision, size);
}
}
}

return (count);
}

/**
 * is_printable - Checks if a character is printable
 * @c: Character to check
 *
 * Return: 1 if printable, 0 otherwise
 */
int is_printable(char c)
{
return (c >= 32 && c < 127);
}
