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
	space_allocation = _strlen(format);

	str = malloc(sizeof(char) * space_allocation);
	tmp = malloc(sizeof(char) * space_allocation / 2);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			checkformat(format[i]);
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
/**
 *checkformat-Checks the format specifier and prints the
 *identified type.
 *@f:Character to check
 *Return:Nothing.
 */
void checkformat(char f)
{
	switch (format[i])
	{
	case 'c':
	{
		str[j] = (char)va_arg(arguments, int);
		j++;
		break;
	}
	case 's':
	{
		string_copy = va_arg(arguments, char*);
		_strncpy(&str[j], string_copy);
		j += _strlen(string_copy);
		break;
	}
	case '%':
	{
		str[j] = '%';
		j++;
		break;
	}

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
