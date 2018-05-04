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

void illustration(sfRenderWindow *window, size_t button,
		  intro_adventure_t *ad_intro)
{
	static size_t i = 0;
	static size_t tmp = 0;

	TRANS_RECT_COND;
	if (tmp != button) {
		i = 0;
		tmp = button;
	} if (button == 0)
		  sfRectangleShape_setTexture(ad_intro->rect, ad_intro->texture, sfTrue); //iam wait spr
	if (button == 1)
		sfRectangleShape_setTexture(ad_intro->rect, ad_intro->texture, sfTrue); //iam wait spr
	if (button == 2)
		sfRectangleShape_setTexture(ad_intro->rect, ad_intro->texture, sfTrue);//iam wait spr
	if (button == 3)
		sfRectangleShape_setTexture(ad_intro->rect, ad_intro->texture, sfTrue);//iam wait spr
	if (button == 4)
		sfRectangleShape_setTexture(ad_intro->rect, ad_intro->texture, sfTrue);//iam wait spr
	if (button == 5)
		sfRectangleShape_setTexture(ad_intro->rect, ad_intro->texture, sfTrue);//iam wait spr
	sfRenderWindow_drawRectangleShape(window, ad_intro->rect, NULL);
}
