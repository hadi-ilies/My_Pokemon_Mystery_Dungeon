/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
*/

#include "prototype.h"

#define TEXTURE_RECT "resources/texture/menu/texture.jpg"
#define BACK "resources/texture/menu/menu_back.jpg"

typedef struct
{
	sfRectangleShape *rect[3];
	sfTexture *texture;
	sfColor color[3];
	sfText *text;
	sfFont *font;

} menu_t;
