/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include "game_resource.h"
#include "item_tab.h"
#include "macro.h"

static void item_aff2(sfRenderWindow *window, enum item_e inventory[INVENTORY_SIZE])
{
	sfRectangleShape *rectangle = sfRectangleShape_create();
	sfTexture *texture = sfTexture_createFromFile(item_file_name[inventory[0]], NULL);
	sfVector2f size = {300, 300};
	sfVector2f pos = {WINDOW_SIZE.x * 0.6, WINDOW_SIZE.y / 2 - size.y / 2};

	if (texture == NULL)
		return;
	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	sfTexture_destroy(texture);
	sfRectangleShape_destroy(rectangle);
}

static void item_aff(sfRenderWindow *window, garou_t *garou)
{
	sfRectangleShape *rectangle = sfRectangleShape_create();
	sfTexture *texture = sfTexture_createFromFile(STAT_RECT, NULL);
	sfVector2f size = {300, 300};
	sfVector2f pos = {WINDOW_SIZE.x * 0.6, WINDOW_SIZE.y / 2 - size.y / 2};
	sfColor color = {0, 250, 0, 255};

	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	sfRectangleShape_setFillColor(rectangle, color);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	if (garou->inventory[0] != NONE)
		item_aff2(window, garou->inventory);
	sfTexture_destroy(texture);
	sfRectangleShape_destroy(rectangle);
}

void inventory_aff(sfRenderWindow *window, garou_t *garou)
{
	sfRectangleShape *rectangle = sfRectangleShape_create();
	sfRectangleShape *rectangle_ombre = sfRectangleShape_create();
	sfTexture *texture = sfTexture_createFromFile(STAT_RECT, NULL);
	sfTexture *texture_ombre = sfTexture_createFromFile(STAT_SHADOW, NULL);
	sfFont *font = sfFont_createFromFile(GAME_FONT);
	sfText *text = sfText_create();
	char *str = malloc(sizeof(char) * 20);
	sfVector2f size = {600, 600};
	sfVector2f pos = {WINDOW_SIZE.x / 8, WINDOW_SIZE.y / 2 - size.y / 2};

	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setPosition(rectangle_ombre, V2F(pos.x + size.x / 20, pos.y + size.y / (6 * 2) - (30 * 2.666) / 2));
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setSize(rectangle_ombre, V2F(500, 30 * 2.666));
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	sfRectangleShape_setTexture(rectangle_ombre, texture_ombre, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);

	sfText_setPosition(text, V2F(pos.x + size.x / 5, pos.y + size.y / (6 * 2) - 30 / 2));
	sfText_setFont(text, font);
	sprintf(str, "HP : %ld/%ld", garou->dungeon.entity[0].life, STAT(garou->dungeon.entity[0], life));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "atk : %ld", STAT(garou->dungeon.entity[0], atk));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "def : %ld", STAT(garou->dungeon.entity[0], def));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "spa : %ld", STAT(garou->dungeon.entity[0], spa));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "spd : %ld", STAT(garou->dungeon.entity[0], spd));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sprintf(str, "speed : %ld", STAT(garou->dungeon.entity[0], speed));
	sfText_setString(text, str);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);

	item_aff(window, garou);

	free(str);
	sfFont_destroy(font);
	sfText_destroy(text);
	sfTexture_destroy(texture);
	sfTexture_destroy(texture_ombre);
	sfRectangleShape_destroy(rectangle);
	sfRectangleShape_destroy(rectangle_ombre);
}
