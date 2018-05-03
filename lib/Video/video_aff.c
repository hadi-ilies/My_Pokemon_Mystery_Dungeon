/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** video_aff.c
*/

#include <stdbool.h>
#include "video.h"

bool video_create_texture(video_t *video)
{
	char *str = video->texture_name[video->num];

	if (video->num >= video->nb_texture)
		return (true);
	video->texture = sfTexture_createFromFile(str, NULL);
	if (video->texture == NULL) {
		video->error = ERR_TEXTURE_CREATE;
		return (true);
	}
	return (false);
}

void time_video(video_t *video, size_t time)
{
	if (time > video->time / video->nb_texture) {
		sfClock_restart(video->clock);
		video->num++;
	}
}

void video_aff(sfRenderWindow *window, video_t *video, sfFloatRect rect)
{
	sfSprite *sprite = video->sprite;
	sfFloatRect bounds;
	sfVector2f scale;
	sfVector2f origin;
	sfTime struct_time = sfClock_getElapsedTime(video->clock);
	size_t time = struct_time.microseconds;

	if (video_create_texture(video))
		return;
	sfSprite_setTexture(sprite, video->texture, sfTrue);
	bounds = sfSprite_getLocalBounds(sprite);
	scale.x = rect.width / bounds.width;
	scale.y = rect.height / bounds.height;
	origin = (sfVector2f){bounds.width / 2, bounds.height / 2};
	sfSprite_setScale(sprite, scale);
	sfSprite_setOrigin(sprite, origin);
	sfSprite_setPosition(sprite, (sfVector2f){rect.left, rect.top});
	sfRenderWindow_drawSprite(window, sprite, NULL);
	time_video(video, time);
	sfTexture_destroy(video->texture);
}
