/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#ifndef MY_H
#define MY_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

int **mem_alloc_2d_array_int(int nb_rows, int nb_cols);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char **load_2d_arr_from_file(char const *filepath, int nb_rows, int nb_cols);
int fs_open_file (char const *filepath);
int my_atoi(char *str);
int my_putstr(char const *str);

#endif
