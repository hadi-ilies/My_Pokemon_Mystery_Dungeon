/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>

size_t my_fprintf(int fd, const char *str, ...);
char *my_getline(int fd);
size_t my_printf(const char *str, ...);
int my_strcmp(const char *a, const char *b);
size_t my_strlen(const char *str);
char **my_str_to_tab(char *command, char *sep);
char *concat_n(char *s1, char *s2, int n);
#endif
