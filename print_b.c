#include "main.h"
/**
  * print_b - print number in binray
  * @n: number used
  * Return: number of characters printed
  */
int print_b(unsigned int n)
{
	char binary[64];
	int index = 0, sum = 0, i;

	if (n == 0)
	{
		print_char('0');
		return (1);
	}
	while (n > 0)
	{
		int remainder = n % 2;

		binary[index++] = remainder + '0';
		n /= 2;
		sum++;
	}

	for (i = index - 1; i >= 0; i--)
	{
		print_char(binary[i]);
	}
	return (sum);
}
