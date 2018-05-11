/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** game_aff.c
*/

#include "game_resource.h"

static bool game_entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f pos)
{
	if (entity->life > 0) {
		entity_aff(window, entity, map, pos);
		if (CLOCK(*entity) < TIME_MOVE)
			return (true);
	}
	return (false);
}

void game_aff(sfRenderWindow *window, garou_t *garou)
{
	sfVector2f pos = entity_get_move_pos(&garou->dungeon.entity[0]);
	sfFloatRect life_rect = {LIFE_RECT};
	bool tmp = true;

	sfRenderWindow_clear(window, sfBlack);
	garou->dungeon.map.pos = pos;
	map_aff(window, &garou->dungeon.map);
	for (size_t i = 0; i < garou->dungeon.nb_entity; i++) {
		entity_t *entity = &garou->dungeon.entity[i];
		map_t *map = &garou->dungeon.map;

		if (game_entity_aff(window, entity, map, pos))
			tmp = false;
	}
	entity_life_aff(window, &garou->dungeon.entity[0], life_rect);
	if (sfKeyboard_isKeyPressed(garou->settings.key[KEY_INVENTORY]))
		inventory_aff(window, garou);
	else if (sfKeyboard_isKeyPressed(garou->settings.key[KEY_ATTACK]))
		tmp ? capacity_aff(window, garou) : 0;
	sfRenderWindow_display(window);
}
