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
	} if (set_one == true) {
		END_PAGE1;
		END_PAGE2;
		END_PAGE3;
		END_PAGE4;
		END_PAGE5;
		END_PAGE6;
	}
	set_one = false;
}

void illustration(sfRenderWindow *window, size_t button,
		  intro_adventure_t *ad_intro)
{
	static size_t i = 0;
	static size_t tmp = 0;
	static bool set_one = true;

	TRANS_RECT_COND;
	if (tmp != button) {
		i = 0;
		tmp = button;
		set_one = true;
	} if (set_one == true) {
		PAGE1;
		PAGE2;
		PAGE3;
		PAGE4;
		PAGE5;
		PAGE6;
	}
	set_one = false;
	sfRenderWindow_drawRectangleShape(window, ad_intro->rect, NULL);
}
