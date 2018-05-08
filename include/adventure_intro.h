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

/*start game need pictures*/
#define PAGE1 button == 0 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define PAGE2 button == 1 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define PAGE3 button == 2 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define PAGE4 button == 3 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define PAGE5 button == 4 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define PAGE6 button == 5 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
/*end game need pictures*/
#define END_PAGE1 button == 0 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define END_PAGE2 button == 1 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define END_PAGE3 button == 2 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define END_PAGE4 button == 3 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define END_PAGE5 button == 4 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define END_PAGE6 button == 5 ? sfRectangleShape_setTexture(ad_intro->rect, \
				ad_intro->texture[0], sfTrue) : 0
#define END_PAGE sfRectangleShape_setTexture(ad_intro.rect, \
				ad_intro.texture[1], sfTrue)
#define RETURN_TO_MENU_WITH_ENTER button >= 6 && event.type == sfEvtKeyPressed \
			&& event.key.code == sfKeyReturn
#define NB_TEXTURE 10
#define PICTURE1 "resources/texture/tmp.png"
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
