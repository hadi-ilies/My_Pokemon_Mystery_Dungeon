/*
** EPITECH PROJECT, 2018
** adventure_intro
** File description:
** adventure_intro
*/

#pragma once

#include "my.h"
#include "prototype.h"
#include <SFML/Graphics.h>

#define RETURN_TO_MENU_WITH_ENTER button >= 6 && event.type == sfEvtKeyPressed \
			&& event.key.code == sfKeyReturn
#define END_PAGE sfRectangleShape_setTexture(ad_intro.rect, \
				ad_intro.texture[6], sfTrue)
#define NB_TEXTURE 10
#define PICTURE1 "resources/texture/tmp.png"
#define PICTURE2 "resources/texture/tmp2.png"
#define PICTURE3 "resources/texture/tmp3.png"
#define PICTURE4 "resources/texture/tmp4.png"
#define END "resources/texture/end.jpg"

typedef struct {
	sfText *text;
	sfFont *font;
	sfRectangleShape *rect;
	sfTexture *texture[NB_TEXTURE];
}intro_adventure_t;

intro_adventure_t ad_intro_create(void);
void adventure_intro(sfRenderWindow *window, menu_t *menu);
void display_history(sfRenderWindow *window, intro_adventure_t *ad_intro,
		size_t button, menu_t *menu);
void illustration(sfRenderWindow *window, size_t button,
		intro_adventure_t *ad_intro);
void ad_intro_destroy(intro_adventure_t *ad_intro);
void illustration_end(size_t button, intro_adventure_t *ad_intro);
void adventure_end(sfRenderWindow *window, menu_t *menu);
