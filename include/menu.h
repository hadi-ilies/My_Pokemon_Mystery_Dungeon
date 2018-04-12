/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
*/

#include "prototype.h"

#define BACK "resources/texture/menu/back/1.png"
#define FONT "pokemon_char.ttf"
#define NB_BUTTON 6
typedef struct
{
	sfRectangleShape *rect[4];
	sfTexture *texture;
	sfColor color[3];
	sfText *text[NB_BUTTON];
	sfFont *font;
	size_t button;
} menu_t;

menu_t menu_create(void);
size_t move_curseur(menu_t *menu, sfEvent *event);
void display_menu(sfRenderWindow *window, menu_t *menu);
void display_texte_button(sfRenderWindow *window, menu_t *menu);
