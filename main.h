#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
/**
  * struct formats - use the right function
  * @sp: the specifer
  * @f: function
  */
typedef struct formats
{
	char sp;
	int (*f)();
} find_function;
int _printf(const char *format, ...);
int  print_char(char c);
int print_integer(int number);
int handle_i(int n);
int  print_string(char *s);
int to_decimal(int number, int flag);
int test_1(char c, va_list args);
int test_2(char c, va_list args);
int print_b(unsigned int n);
int print_reverse(char *str);
int print_rot13(const char *str);
#endif
