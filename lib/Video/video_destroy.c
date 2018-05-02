/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** video_destroy.c
*/

#include <stdlib.h>
#include "video.h"

void video_destroy(video_t *video)
{
	for (size_t i = 0; i < video->nb_texture; i++)
		free(video->texture_name[i]);
	free(video->texture_name);
	sfSprite_destroy(video->sprite);
	sfClock_destroy(video->clock);
}
