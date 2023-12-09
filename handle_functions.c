#include "main.h"
/**
  * print_char - print a single character
  * @c: the character used
  * Return: int
  */
int print_char(char c)
{
	write(STDOUT_FILENO, &c, 1);
	return (1);
}
/**
  * print_string - print a string
  * @s: pointer to a string
  * Return: int
  */
int print_string(char *s)
{
	int i = 0;
	int sum = 0;

	if (!s)
	{
		return (print_string("(null)"));
	}

	while (s[i] != '\0')
	{
		char c = s[i];

		sum += print_char(c);
		i++;
	}
	return (sum);
}
/**
  * print_integer - print a decimal number
  * @number: number used
  * Return: int
  */
int print_integer(int number)
{
	char buffer[20];
	int length = 0;
	int temp = number;
	int is_negative = 0;
	int i, sum = 0;

	if (temp == 0)
	{
		buffer[length++] = '0';
	}
	else if (temp < 0)
	{
		is_negative = 1;
		temp = -temp;
	}
	while (temp != 0)
	{
		buffer[length++] = '0' + (temp % 10);
		temp /= 10;
		sum++;
	}

	if (is_negative)
	{
		buffer[length++] = '-';
	}
	for (i = 0; i < length / 2; i++)
	{
		char temp = buffer[i];

		buffer[i] = buffer[length - i - 1];
		buffer[length - i - 1] = temp;
	}

	write(STDOUT_FILENO, buffer, length);
	return (sum);
}
/**
  * to_decimal - converts the number to decimal
  * @number: the number used
  * @flag: tell us if it's hexa or octal
  * Return: converted number
  */
int to_decimal(int number, int flag)
{
	int decimal_num = 0;

	if (flag == 0)
	{
		int power = 0;

		while (number > 0)
		{
			int digit = number % 10;

			decimal_num += digit * (1 << (3 * power));
			number /= 10;
			power++;
		}
	}
	else
	{
	}
	return (decimal_num);
}
/**
  * handle_i - handles numbers when it's i
  * @n: the number handled
  * Return: void
  */
int handle_i(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += print_char('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += handle_i(num / 10);

	count += print_char('0' + (num % 10));

	return (count);
}
