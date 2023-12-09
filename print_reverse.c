#include "main.h"
/**
  * print_reverse - print a string in reverse
  * @str: pointer to string
  * Return: number of characters printed
  */
int print_reverse(char *str)
{
	int i = 0, sum = 0;

	while (*str != '\0')
	{
		str++;
		sum++;
		i++;
	}
	str--;
	while (i > 0)
	{
		print_char(*str);
		str--;
		i--;
	}
	return (sum);
}
