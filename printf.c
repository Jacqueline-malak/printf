#include "main.h"
/**
 * print_normal-print percent at other charecter
 * @c:character printed
 * Return: int
 **/
int print_normal(char c)
{
	if (c == '\0')
	{
		return (-1);
	}
	print_char('%');
	return (print_char(c) + 1);
}
/**
 * handle -handle specifier
 * @args:decision parameter
 * @format: string
 * Return: numbers of characters
 **/
int handle(const char *format, va_list args)
{
	int sum = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			sum += test_1(*format, args);
			if (!sum && format)
				sum += print_normal(*format);
		}
		else
			sum += print_char(*format);
		format++;
	}
	return (sum);
}
/**
 * _printf - Custom printf function
 * @format: Pointer to a constant format string
 *
 * Description:
 * This function prints formatted output to the standard output (stdout),
 * based on the format string and additional arguments provided.
 *
 * Return:
 * The number of characters printed on success, or -1 on error.
 **/
int _printf(const char *format, ...)
{
	va_list args;
	int sum = 0;

	if (!format)
	{
		return (-1);
	}

	va_start(args, format);
	sum += handle(format, args);
	va_end(args);
	return (sum);
}

