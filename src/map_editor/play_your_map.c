/*
** EPITECH PROJECT, 2018
** play_your_map
** File description:
** play_your_map
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "prototype.h"
#include "tile_name.h"
#include "macro.h"
#include "map_editor_function.h"

static entity_t *generate_entitys(size_t nb_entity)
{
	entity_t *entity = malloc(sizeof(entity_t) * nb_entity);

	if (entity == NULL)
		return (NULL);
	for (size_t i = 1; i < nb_entity; i++) {
		entity[i] = entity_create_from_file("resources/entity/nomy");
		if (entity[i].error != ERR_OK)
			return (NULL);
	}
	return (entity);
}

static dungeon_t generate_dungeon(size_t nb_stage, map_t *map)
{
	dungeon_t dungeon = dungeon_create();

	dungeon.nb_stage = nb_stage;
	dungeon.nb_entity = 20;
	dungeon.map = map_copy(map);
	dungeon.map.size = V2F(GAME_ZOOM, GAME_ZOOM);
	dungeon.entity = generate_entitys(dungeon.nb_entity);
	return (dungeon);
}

static sfVector2i rand_pos(map_t *map)
{
	sfVector2i pos;

	do {
		pos.x = rand() % map->nb_case_x;
		pos.y = rand() % map->nb_case_y;
	}
	while (map->tab[pos.x][pos.y].type != GROUND);
	return (pos);
}

static int run(sfRenderWindow *window, garou_t *garou)
{
	size_t level = garou->player.level - 1;

	for (size_t i = 1; i < garou->dungeon.nb_entity; i++) {
		size_t life = STAT(garou->dungeon.entity[i], life);

		garou->dungeon.entity[i].level = level;
		garou->dungeon.entity[i].life = life;
		garou->dungeon.entity[i].ia = 1;
		garou->dungeon.entity[i].dir = V2I(0, 0);
		garou->dungeon.entity[i].pos = rand_pos(&garou->dungeon.map);
	}
	garou->dungeon.entity[0].dir = V2I(0, 0);
	garou->dungeon.entity[0].pos = rand_pos(&garou->dungeon.map);
	return (game_loop(window, garou));
}

void play_your_map(sfRenderWindow *window, map_t *map)
{
	garou_t garou = garou_create(CONFIG);

	garou.player = entity_create_from_file("resources/entity/my");
	garou.player.ia = 0;
	if (garou.player.error != ERR_OK)
		return;
	garou.dungeon = generate_dungeon(1, map);
	if (garou.dungeon.map.error != ERR_OK)
		return;
	if (garou.dungeon.entity == NULL)
		return;
	garou.dungeon.entity[0] = garou.player;
	run(window, &garou);
	dungeon_destroy(&garou.dungeon);
	garou_destroy(&garou);
}
