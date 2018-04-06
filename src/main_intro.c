/*
** EPITECH PROJECT, 2018
** main_intro
** File description:
** main_intro
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

int error_anime(video_t video)
{
	if (video.error != VIDEO_OK) {
		printf("err : %d\n", video.error);
		return (84);
	}
	return (0);
}

void loop_event(video_t video, bool *exit, sfRenderWindow *window, sfEvent *event)
{
	while(sfRenderWindow_pollEvent(window, event)) {
		if(event->type == sfEvtClosed)
			sfRenderWindow_close(window);
		if(event->type == sfEvtKeyPressed
		&& video.num >= video.nb_texture - 1)
			*exit = true;
	}
}

int main_intro(sfRenderWindow *window, sfEvent *event)
{
	sfMusic *music[3];
	loading_t load = loading_create(window);
	anime_tab_t animation = anime_tab_create_from_file(ANIME_START_FILE);
	video_t video = video_create_from_file(ANIME_INTRO_FILE);
	bool exit = false;

	if (destroy_and_check_error_anime(&video, &load) == 84)
		return (84);
	music_create(music);
	while(sfRenderWindow_isOpen(window) && exit == false) {
		loop_event(video, &exit, window, event);
		sfRenderWindow_clear(window, sfBlack);
		video_aff(window, &video, WIN_REC);
		get_start(&animation, music, window, &video);
		sfRenderWindow_display(window);
	}
	destroy_factories(&animation, music, window, &video);
	return (0);
}
