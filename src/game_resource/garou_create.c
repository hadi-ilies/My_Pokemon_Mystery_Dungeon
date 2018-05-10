/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** garou_create.c
*/

#include "game_resource.h"

static sfMusic *music_create(char *file_name, settings_t *settings)
{
	sfMusic *music = sfMusic_createFromFile(file_name);

	if (music == NULL)
		return (NULL);
	sfMusic_setVolume(music, settings->music_volume);
	sfMusic_setLoop(music, sfTrue);
	return (music);
}

garou_t garou_create(char *settings_file_name)
{
	garou_t garou;

	garou.dungeon = dungeon_create();
	for (size_t i = 0; i < INVENTORY_SIZE; i++)
		garou.inventory[i] = NONE;
	garou.settings = settings_load(settings_file_name);
	garou.music = music_create(GAME_MUSIC, &garou.settings);
	return (garou);
}
