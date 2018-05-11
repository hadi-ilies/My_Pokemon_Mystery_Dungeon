/*
** EPITECH PROJECT, 2018
** create_back_icon
** File description:
** create_back_icon
*/

#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "settings.h"
#include "adventure_intro.h"

void back_create_icon(loading_t *optional)
{
	optional->icon_back = sfRectangleShape_create();
	optional->texture_icon = sfTexture_createFromFile(TITLE, NULL);
	sfRectangleShape_setSize(optional->icon_back,
				V2F(800, 358));
	sfRectangleShape_setOrigin(optional->icon_back,
				V2F(400, 358 / 2));
	sfRectangleShape_setPosition(optional->icon_back,
				V2F(1920 / 2, 1080 / 2 - 358 / 2));
	sfRectangleShape_setFillColor(optional->icon_back,
				COL(255, 255, 255, 120));
}
