#include "main.h"
/**
 *  test_1 -test for specifier
 *  @c: character
 *  @args: list of arguments
 *  Return: number of character printed
 **/
int test_1(char c, va_list args)
{
	int sum = 0, i;
	char c2, *s;

	if (c == 'c')
	{
		c2 = va_arg(args, int);
		sum += print_char(c2);
	}
	else if (c == 's')
	{
		s = va_arg(args, char *);
		sum += print_string(s);
	}
	else if (c == '%')
	{
		sum += print_char('%');
	}
	else if (c == 'd')
	{
		i = va_arg(args, int);
		sum += handle_i(i);
	}
	else if (c == 'i')
	{
		i = va_arg(args, int);
		sum += handle_i(i);
	}
	else
		return (test_2(c, args));
	return (sum);
}
/**
  * test_2 - check specifer
  * @c: character used
  * @args: list of arguments
  * Return: number of characters printed
  */
int test_2(char c, va_list args)
{
	unsigned int b;
	int sum = 0;
	char *s;

	if (c == 'b')
	{
		b = va_arg(args, unsigned int);
		sum += print_b(b);
	}
	else if (c == 'r')
	{
		s = va_arg(args, char *);
		sum += print_reverse(s);
	}
	else if (c == 'R')
	{
		s = va_arg(args, char *);
		sum += print_rot13(s);
	}
	else
		return (0);
	return (sum);
}
