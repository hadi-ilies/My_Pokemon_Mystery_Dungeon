/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** anime_tab_aff.c
*/

#include "anime_tab.h"

void anime_tab_aff(sfRenderWindow *window, anime_tab_t *anime_tab,
		   sfFloatRect rect)
{
	sfSprite *sprite = anime_tab->sprite;
	sfFloatRect bounds;
	sfVector2f scale;
	sfVector2f origin;
	sfTime struct_time = sfClock_getElapsedTime(anime_tab->clock);
	size_t time = struct_time.microseconds;

	sfSprite_setTexture(sprite, anime_tab->texname[anime_tab->anime[anime_tab->num].rectex[anime_tab->anime[anime_tab->num].num].texture_num].texture, sfTrue);
	sfSprite_setTextureRect(sprite, anime_tab->anime[anime_tab->num].rectex[anime_tab->anime[anime_tab->num].num].rect);
	bounds = sfSprite_getLocalBounds(sprite);
	scale.x = rect.width / bounds.width;
	scale.y = rect.height / bounds.height;
	origin.x = bounds.width / 2;
	origin.y = bounds.height / 2;
	sfSprite_setScale(sprite, scale);
	sfSprite_setOrigin(sprite, origin);
	sfSprite_setPosition(sprite, (sfVector2f){rect.left, rect.top});
	sfRenderWindow_drawSprite(window, sprite, NULL);
	if (time > anime_tab->anime[anime_tab->num].time / anime_tab->anime[anime_tab->num].nb_rectex) {
		sfClock_restart(anime_tab->clock);
		anime_tab->anime[anime_tab->num].num++;
		if (anime_tab->anime[anime_tab->num].num >= anime_tab->anime[anime_tab->num].nb_rectex)
			anime_tab->anime[anime_tab->num].num = 0;
	}
}
