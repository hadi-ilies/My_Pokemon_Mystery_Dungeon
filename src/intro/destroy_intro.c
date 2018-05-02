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
		video_t *video)
{
	anime_tab_destroy(animation);
	video_destroy(video);
	destroy_music(music);
}

int destroy_and_check_error_anime(anime_tab_t *animation, video_t *video)
{
	if (animation->error != ERR_OK || video->error != ERR_OK)
		return (1);
	return (0);
}
