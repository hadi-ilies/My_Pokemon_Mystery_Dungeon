/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>
#include <unistd.h>

#define my_printf(str, ...) my_fprintf(STDOUT_FILENO, str, __VA_ARGS__)

size_t my_fprintf(int fd, const char *str, ...);
char *my_getline(int fd);
int my_strcmp(const char *a, const char *b);
char *my_strdup(const char *str);
size_t my_strlen(const char *str);
char *my_strncat(char *s1, char *s2, size_t n);
char **my_str_to_tab(char *command, char *sep);

#endif
