/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** video_aff.c
*/

#include "video.h"

void video_aff(sfRenderWindow *window, video_t *video, sfFloatRect rect)
{
	sfSprite *sprite = video->sprite;
	sfFloatRect bounds;
	sfVector2f scale;
	sfVector2f origin;
	sfTime struct_time = sfClock_getElapsedTime(video->clock);
	size_t time = struct_time.microseconds;

	if (video->num >= video->nb_texture)
		return;
	video->texture = sfTexture_createFromFile(video->texture_name[video->num], NULL);
	if (video->texture == NULL) {
		video->error = VIDEO_TEXTURE_CREATE;
		return;
	}
	sfSprite_setTexture(sprite, video->texture, sfTrue);
	bounds = sfSprite_getLocalBounds(sprite);
	scale.x = rect.width / bounds.width;
	scale.y = rect.height / bounds.height;
	origin.x = bounds.width / 2;
	origin.y = bounds.height / 2;
	sfSprite_setScale(sprite, scale);
	sfSprite_setOrigin(sprite, origin);
	sfSprite_setPosition(sprite, (sfVector2f){rect.left, rect.top});
	sfRenderWindow_drawSprite(window, sprite, NULL);
	if (time > video->time / video->nb_texture) {
		sfClock_restart(video->clock);
		video->num++;
	}
	sfTexture_destroy(video->texture);
}
