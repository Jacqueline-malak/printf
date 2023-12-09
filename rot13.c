#include "main.h"
/**
 * print_rot13- print str in rot13
 * @str: string used
 * Return: number of character printed
 **/
int print_rot13(const char *str)
{
	int i, sum = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		char c = str[i];

		if (c >= 'a' && c <= 'z')
		{
			c = 'a' + (c - 'a' + 13) % 26;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c = 'A' + (c - 'A' + 13) % 26;
		}
		sum += print_char(c);
	}
	return (sum);
}
