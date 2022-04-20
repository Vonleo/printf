#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* print_nums function*/
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_bases function*/
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* converter function*/
char *convert(unsigned long int num, int base, int lowercase);

/* _printf function*/
int _printf(const char *format, ...);

/* get_print function*/
int (*get_print(char s))(va_list, flags_t *);

/* get_flag function*/
int get_flag(char s, flags_t *f);

/* print_alpha function*/
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* write_funcs function*/
int _putchar(char c);
int _puts(char *str);

/* print_custom function*/
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* print_address function*/
int print_address(va_list l, flags_t *f);

/* print_percent function*/
int print_percent(va_list l, flags_t *f);

#endif
