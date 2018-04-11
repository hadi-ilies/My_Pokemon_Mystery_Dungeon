/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
*/

#include "prototype.h"

#define BACK "resources/texture/menu/back/1.png"

typedef struct
{
	sfRectangleShape *rect[3];
	sfTexture *texture;
	sfColor color[3];
	sfText *text;
	sfFont *font;

} menu_t;
