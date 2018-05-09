/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** main.c
*/

#include "prototype.h"

int main(void)
{
	sfRenderWindow *window = window_create();

	if (window == NULL)
		return (84);
	sfRenderWindow_display(window);
	return (main_menu(window));
}
