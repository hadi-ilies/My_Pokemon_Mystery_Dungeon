/*
** EPITECH PROJECT, 2018
** main_intro
** File description:
** main_intro
*/

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "anime_tab.h"
#include "prototype.h"
#include "loading.h"
#include "video.h"
#include "macro.h"

void loop_event(video_t video, bool *exit, sfRenderWindow *window, sfEvent *event)
{
	while(sfRenderWindow_pollEvent(window, event)) {
		if(event->type == sfEvtClosed)
			sfRenderWindow_close(window);
		if(event->type == sfEvtKeyPressed
		&& video.num >= video.nb_texture)
			*exit = true;
	}
}

bool transition(sfRenderWindow *window)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f size = {WINDOW_SIZE.x, WINDOW_SIZE.y};
	static int trans = 0;

	sfRectangleShape_setFillColor(rect, (sfColor) {0, 0, 0, 10});
	sfRectangleShape_setSize(rect, size);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfRectangleShape_destroy(rect);
	trans += 10;
	if (trans < 500)
		return (false);
	trans = 0;
	return (true);
}

int main_intro(sfRenderWindow *window, sfEvent *event)
{
	sfMusic *music[3];
	loading_t load = loading_create(window);
	anime_tab_t animation = anime_tab_create_from_file(ANIME_START_FILE);
	video_t video = video_create_from_file(ANIME_INTRO_FILE);
	bool exit = false;

	if (destroy_and_check_error_anime(&animation, &load, &video) == 1)
		return (0);
	music_create(music);
	while(sfRenderWindow_isOpen(window)) {
		loop_event(video, &exit, window, event);
		exit == false ? sfRenderWindow_clear(window, sfBlack) : 0;
		exit == false ? video_aff(window, &video, WIN_REC) : 0;
		exit == false ? get_start(&animation, music, window, &video, event) : 0;
		if (exit == true && transition(window) || video.error != VIDEO_OK)
			break;
		sfRenderWindow_display(window);
	}
	destroy_factories(&animation, music, &video);
	return (0);
}
