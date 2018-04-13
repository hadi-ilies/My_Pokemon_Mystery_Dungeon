/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** destroy
*/
#include "prototype.h"
#include "main_menu/menu.h"

void menu_destroy(menu_t *menu)
{
	for (size_t i = 0; i < 4; i++)
		sfRectangleShape_destroy(menu->rect[i]);
	for (size_t i = 0; i < NB_BUTTON; i++)
		sfText_destroy(menu->text[i]);
	sfFont_destroy(menu->font);
}

void back_destroy(loading_t *back)
{
	sfSprite_destroy(back->sprite);
	sfTexture_destroy(back->texture);
}

void destroy_all(loading_t *back, sfRenderWindow *window, menu_t *menu)
{
	back_destroy(back);
	menu_destroy(menu);
	sfRenderWindow_destroy(window);
}
