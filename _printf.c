#include "holberton.h"
/**
 *_printf-variadic function that Prints to stdout.
 *@format:Format specifier.
 *
 *Return:Total number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int i = 0, j = 0, space_allocation;
	char *str, *tmp;
	char *string_copy;

	va_start(arguments, format);
	space_allocation = 1024;

	str = malloc(sizeof(char) * space_allocation);
	tmp = malloc(sizeof(char) * space_allocation / 2);

	if (str == NULL || tmp == NULL)
	{
		free(str);
		free(tmp);
		return (-1);
	}

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				/* Convert char */
				case 'c':
					{
						str[j] = (char)va_arg(arguments, int);
						j++;
						break;
					}

					/* copy string */
				case 's':
					{
						string_copy = va_arg(arguments, char*);
						_strncpy(&str[j], string_copy);
						j += _strlen(string_copy);
						break;
					}

					/* copy string */
				case '%':
					{
						str[j] = '%';
						j++;
						break;
					}

					/* Convert decimal */
				case 'd':
					{
						_itoa(va_arg(arguments, int), tmp, 10);
						_strncpy(&str[j], tmp);
						j += _strlen(tmp);
						break;
					}
				case 'i':
					{
						_itoa(va_arg(arguments, int), tmp, 10);
						_strncpy(&str[j], tmp);
						j += _strlen(tmp);
						break;

					}
			}
		}
		else
		{
			str[j] = format[i];
			j++;
		}
		i++;
	}

	write(1, str, j);
	va_end(arguments);
	return (j);
}
