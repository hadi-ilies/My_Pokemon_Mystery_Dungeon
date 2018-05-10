/*
** EPITECH PROJECT, 2018
** stat_aff
** File description:
** stat_aff
*/

#include "game_resource.h"
#include "macro.h"
#include "my.h"

void hp_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfFont *font)
{
	sfVector2f size = {600, 600};
	char *str1 = inttostr(garou->dungeon.entity[0].life);
	char *str2 = inttostr(STAT(garou->dungeon.entity[0], life));
	char *string = concat(concat(str1, "/"), str2);
	sfVector2f pos = {WINDOW_SIZE.x / 8, WINDOW_SIZE.y / 2 - size.y / 2};

	sfText_setPosition(text,
	V2F(pos.x + size.x / 5, pos.y + size.y / (6 * 2) - 30 / 2));
	sfText_setFont(text, font);
	sfText_setString(text, concat("Health : ", string));
	sfRenderWindow_drawText(window, text, NULL);
}

void atk_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre)
{
	sfVector2f size = {600, 600};
	char *str = inttostr(STAT(garou->dungeon.entity[0], atk));
	char *string = concat("Attack : ", str);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sfText_setString(text, string);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);
}

void def_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre)
{
	sfVector2f size = {600, 600};
	char *str = inttostr(STAT(garou->dungeon.entity[0], def));
	char *string = concat("Defense : ", str);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sfText_setString(text, string);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);
}

void spa_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre)
{
	sfVector2f size = {600, 600};
	char *str = inttostr(STAT(garou->dungeon.entity[0], spa));
	char *string = concat("S. Attack : ", str);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sfText_setString(text, string);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);
}

void spd_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre)
{
	sfVector2f size = {600, 600};
	char *str = inttostr(STAT(garou->dungeon.entity[0], spd));
	char *string = concat("S. Defense : ", str);

	sfText_move(text, V2F(0, size.y / 6));
	sfRectangleShape_move(rectangle_ombre, V2F(0, size.y / 6));
	sfText_setString(text, string);
	sfRenderWindow_drawRectangleShape(window, rectangle_ombre, NULL);
	sfRenderWindow_drawText(window, text, NULL);
}
