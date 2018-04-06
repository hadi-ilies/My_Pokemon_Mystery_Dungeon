/*
** EPITECH PROJECT, 2018
** facto
** File description:
** facto
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "anime_tab.h"
#include "prototype.h"
#include "loading.h"
#include "video.h"
#include "macro.h"

void get_start(anime_tab_t *animation, sfMusic *music[3],
	sfRenderWindow *window, video_t *video)
{
	static bool cond = true;

	sfKeyboard_isKeyPressed(sfKeySpace) == true
		? video->num = video->nb_texture : 0;
	if (video->num >= video->nb_texture - 1) {
		anime_tab_aff(window, animation, WIN_REC);
		if (cond == true) {
			sfMusic_play(music[1]);
			sfMusic_setVolume(music[0], 30);
			cond = false;
		}
	}
}

loading_t loading_create(sfRenderWindow *window)
{
	loading_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(LOAD, NULL);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	sfRenderWindow_drawSprite(window, optional.sprite, NULL);
	return (optional);
}
