/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

static size_t my_putstr(const char *str)
{
	size_t i = 0;

	for (; str[i] != '\0'; i++);
	return (write(STDOUT_FILENO, str, i));
}

static size_t my_putint(int nb)
{
	char c[2] = {'\0'};
	size_t size = 0;

	if (nb < 0) {
		c[0] = '-';
		size += write(STDOUT_FILENO, c, 1);
		nb = -nb;
	}
	nb / 10 > 0 ? size += my_putint(nb / 10) : 0;
	c[0] = nb % 10 + '0';
	size += write(STDOUT_FILENO, c, 1);
	return (size);
}

static size_t my_putdouble(double nb)
{
	size_t size = my_putint((int)nb);
	char c[2] = ".";

	nb -= (int)nb;
	for (size_t i = 0; i < 8; nb *= 10, i++);
	size += write(STDOUT_FILENO, c, 1);
	size += my_putint((int)nb);
	return (size);
}

static size_t print_var(va_list arg, const char type)
{
	size_t size = 0;

	if (type == 'c') {
		char c[2] = {va_arg(arg, int), '\0'};

		size += write(STDOUT_FILENO, c, 1);
	}
	type == 's' ? size += my_putstr(va_arg(arg, char *)) : 0;
	type == 'd' ? size += my_putint(va_arg(arg, int)) : 0;
	type == 'f' ? size += my_putdouble(va_arg(arg, double)) : 0;
	return (size);
}

size_t my_printf(const char *str, ...)
{
	va_list arg;
	size_t size = 0;

	va_start(arg, str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '%') {
			size += print_var(arg, str[i + 1]);
			i++;
		}
		else
			size += write(STDOUT_FILENO, str + i, 1);
	}
	va_end(arg);
	return (size);
}
