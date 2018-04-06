/*
** EPITECH PROJECT, 2018
** destroy_intro
** File description:
** destroy_intro
*/

#include "anime_tab.h"
#include "prototype.h"
#include "loading.h"
#include "video.h"
#include "macro.h"

void destroy_factories(anime_tab_t *animation, sfMusic *music[3],
		sfRenderWindow *window, video_t *video)
{
	anime_tab_destroy(animation);
	video_destroy(video);
	destroy_music(music);
	sfRenderWindow_destroy(window);
}

int destroy_and_check_error_anime(video_t *video, loading_t *load)
{
	if (error_anime(*video) == 84)
		return (84);
	sfSprite_destroy(load->sprite);
	sfTexture_destroy(load->texture);
}
