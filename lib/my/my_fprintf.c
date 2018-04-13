/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

static size_t my_fputstr(int fd, const char *str)
{
	size_t i = 0;

	for (; str[i] != '\0'; i++);
	return (write(fd, str, i));
}

static size_t my_fputint(int fd, int nb)
{
	char c[2] = {'\0'};
	size_t size = 0;

	if (nb < 0) {
		c[0] = '-';
		size += write(fd, c, 1);
		nb = -nb;
	}
	nb / 10 > 0 ? size += my_fputint(fd, nb / 10) : 0;
	c[0] = nb % 10 + '0';
	size += write(fd, c, 1);
	return (size);
}

static size_t my_fputdouble(int fd, double nb)
{
	size_t size = my_fputint(fd, (int)nb);
	char c[2] = ".";

	nb -= (int)nb;
	for (size_t i = 0; i < 8; nb *= 10, i++);
	size += write(fd, c, 1);
	size += my_fputint(fd, (int)nb);
	return (size);
}

static size_t fprint_var(int fd, va_list arg, const char type)
{
	size_t size = 0;

	if (type == 'c') {
		char c[2] = {va_arg(arg, int), '\0'};

		size += write(fd, c, 1);
	}
	type == 's' ? size += my_fputstr(fd, va_arg(arg, char *)) : 0;
	type == 'd' ? size += my_fputint(fd, va_arg(arg, int)) : 0;
	type == 'f' ? size += my_fputdouble(fd, va_arg(arg, double)) : 0;
	return (size);
}

size_t my_fprintf(int fd, const char *str, ...)
{
	va_list arg;
	size_t size = 0;

	va_start(arg, str);
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '%') {
			size += fprint_var(fd, arg, str[i + 1]);
			i++;
		}
		else
			size += write(fd, str + i, 1);
	}
	va_end(arg);
	return (size);
}
