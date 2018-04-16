/*
** EPITECH PROJECT, 2018
** optional_create
** File description:
** optional_create
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include "prototype.h"
#include "tile_name.h"
#include "macro.h"
#include "map_editor_function.h"

back_and_music_t optional_create(void)
{
	back_and_music_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(BACK_MAP, NULL);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	optional.music = sfMusic_createFromFile(MUSIC_EDITOR);
	sfMusic_play(optional.music);
	sfMusic_setLoop(optional.music, true);
	return (optional);
}
