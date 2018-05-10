/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game.c
*/

#include "game_resource.h"
#include "item_tab.h"
#include "macro.h"
#include "my.h"

static void item_aff2(sfRenderWindow *window,
		enum item_e inventory[INVENTORY_SIZE])
{
	sfRectangleShape *rectangle = sfRectangleShape_create();
	sfTexture *texture =
		sfTexture_createFromFile(item_file_name[inventory[0]], NULL);
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

static void display_rc_inventory(sfRenderWindow *window,
	sfTexture *texture_ombre, sfRectangleShape *rectangle_ombre)
{
	sfVector2f size = {600, 600};
	sfVector2f pos = {WINDOW_SIZE.x / 8, WINDOW_SIZE.y / 2 - size.y / 2};
	sfRectangleShape *rectangle = sfRectangleShape_create();
	sfTexture *texture = sfTexture_createFromFile(STAT_RECT, NULL);

	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setPosition(rectangle_ombre,
	V2F(pos.x + size.x / 20, pos.y + size.y / (6 * 2) - (30 * 2.666) / 2));
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setSize(rectangle_ombre, V2F(500, 30 * 2.666));
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	sfRectangleShape_setTexture(rectangle_ombre, texture_ombre, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfTexture_destroy(texture);
	sfRectangleShape_destroy(rectangle);
}

static void speed_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre)
{
	sfVector2f size = {600, 600};
	char *str = inttostr(STAT(garou->dungeon.entity[0], speed));
	char *string = concat("Speed : ", str);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sfText_setString(text, string);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);
}

void inventory_aff(sfRenderWindow *window, garou_t *garou)
{
	sfTexture *texture_ombre = sfTexture_createFromFile(STAT_SHADOW, NULL);
	sfRectangleShape *rectangle_ombre = sfRectangleShape_create();
	sfFont *font = sfFont_createFromFile(GAME_FONT);
	sfText *text = sfText_create();

	display_rc_inventory(window, texture_ombre, rectangle_ombre);
	hp_stat(garou, window, text, font);
	atk_stat(garou, window, text, rectangle_ombre);
	def_stat(garou, window, text, rectangle_ombre);
	spa_stat(garou, window, text, rectangle_ombre);
	spd_stat(garou, window, text, rectangle_ombre);
	speed_stat(garou, window, text, rectangle_ombre);
	item_aff(window, garou);
	sfFont_destroy(font);
	sfText_destroy(text);
	sfTexture_destroy(texture_ombre);
	sfRectangleShape_destroy(rectangle_ombre);
}
