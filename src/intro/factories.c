/*
** EPITECH PROJECT, 2018
** facto
** File description:
** facto
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "anime_tab.h"
#include "prototype.h"
#include "loading.h"
#include "video.h"
#include "macro.h"

void press_key_cond(sfMusic *music[3], sfRectangleShape *rect,
		sfTexture *texture, bool *cond)
{
	sfRectangleShape_setSize(rect, (sfVector2f) {800, 150});
	sfRectangleShape_setOrigin(rect, (sfVector2f) {400, 75});
	sfRectangleShape_setPosition(rect, (sfVector2f) {1920 / 2 + 150, 800});
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfMusic_play(music[1]);
	sfMusic_setVolume(music[0], 30);
	*cond = false;
}

void get_start(anime_tab_t *animation, sfMusic *music[3],
	       sfRenderWindow *window, video_t *video, sfEvent *event)
{
	static bool cond = true;
	static sfRectangleShape *rect;
	static sfTexture *texture;
	static int trans = 255;
	static int size_w = 800;
	static int size_h = 150;

	event->key.code == sfKeySpace ? video->num = video->nb_texture : 0;
	if (video->num >= video->nb_texture - 1) {
		anime_tab_aff(window, animation, WIN_REC);
		if (cond == true) {
			rect = sfRectangleShape_create();
			texture = sfTexture_createFromFile(PRESS_KEY, NULL);
			press_key_cond(music, rect, texture, &cond);
		}
		cond == false ? COND_AFF : 0;
		cond == false ? COND_TRANS : 0;
		cond == false ? COND_WIDTH : 0;
	}
}
