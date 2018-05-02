/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** video_create.c
*/

#include "video.h"

video_t video_create(void)
{
	video_t video;

	video.nb_texture = 0;
	video.texture_name = NULL;
	video.texture = NULL;
	video.sprite = sfSprite_create();
	video.clock = sfClock_create();
	video.time = 0;
	video.num = 0;
	if (video.sprite == NULL)
		video.error = ERR_SPRITE_CREATE;
	else if (video.clock == NULL)
		video.error = ERR_CLOCK_CREATE;
	else
		video.error = ERR_OK;
	return (video);
}
