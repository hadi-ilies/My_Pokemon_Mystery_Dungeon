/*
1;4804;0c** EPITECH PROJECT, 2018
** adventure_intro
** File description:
** adventure_intro
*/

#pragma once

#include "my.h"
#include "prototype.h"
#include <SFML/Graphics.h>

typedef struct {
	sfText *text;
	sfFont *font;
	sfRectangleShape *rect;
}intro_adventure_t;

intro_adventure_t ad_intro_create(void);
void adventure_intro(sfRenderWindow *window, menu_t *menu);
void display_history(sfRenderWindow *window, intro_adventure_t *ad_intro,
		size_t button, menu_t *menu);
