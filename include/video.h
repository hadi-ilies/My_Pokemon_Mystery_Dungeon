/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** video.h
*/

#ifndef VIDEO_H_
#define VIDEO_H_

#include <SFML/Graphics.h>
#include <stddef.h>

enum video_error {
	VIDEO_OK,
	VIDEO_TEXTURE_CREATE,
	VIDEO_SPRITE_CREATE,
	VIDEO_CLOCK_CREATE,
	VIDEO_OPEN,
	VIDEO_READ,
	VIDEO_MALLOC,
	VIDEO_INVALID_NUMBER
};

typedef struct {
	size_t nb_texture;
	char **texture_name;
	sfTexture *texture;
	sfSprite *sprite;
	sfClock *clock;
	size_t time;
	size_t num;
	size_t error;
} video_t;

video_t video_create(void);
video_t video_create_from_fd(int fd);
video_t video_create_from_file(char *file_name);
void video_aff(sfRenderWindow *window, video_t *video, sfFloatRect rect);
void video_destroy(video_t *video);

#endif
