/*
** EPITECH PROJECT, 2018
** illutr
** File description:
** illustration
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "adventure_intro.h"

void illustration_end(size_t button, intro_adventure_t *ad_intro)
{
	static size_t i = 0;
	static size_t tmp = 0;
	static bool set_one = true;

	TRANS_RECT_COND;
	if (tmp != button) {
		i = 0;
		tmp = button;
		set_one = true;
	} if (set_one == true)
		sfRectangleShape_setTexture(ad_intro->rect,
					ad_intro->texture[tmp], sfTrue);
	set_one = false;
}

void illustration(sfRenderWindow *window, size_t button,
		intro_adventure_t *ad_intro, bool *set_one)
{
	static size_t i = 0;
	static size_t tmp = 0;

	TRANS_RECT_COND;
	if (tmp != button) {
		i = 0;
		tmp = button;
		*set_one = true;
	} if (*set_one == true)
	sfRectangleShape_setTexture(ad_intro->rect,
				ad_intro->texture[tmp], sfTrue);
	*set_one = false;
	sfRenderWindow_drawRectangleShape(window, ad_intro->rect, NULL);
}
