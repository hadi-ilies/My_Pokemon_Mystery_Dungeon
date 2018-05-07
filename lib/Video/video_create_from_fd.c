/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** video_create_from_fd.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "video.h"

bool error_video(video_t *video, int fd)
{
	if (video->error != ERR_OK)
		return (false);
	if (read(fd, &video->nb_texture, sizeof(size_t)) != sizeof(size_t)) {
		video->error = ERR_READ;
		return (false);
	}
	if (video->nb_texture <= 0) {
		video->error = ERR_INVALID_NUMBER;
		return (false);
	}
	video->texture_name = malloc(sizeof(char *) * video->nb_texture);
	if (video->texture_name == NULL) {
		video->error = ERR_MALLOC;
		return (false);
	}
	return (true);
}

bool get_error_video(video_t *video, int fd)
{
	for (size_t i = 0; i < video->nb_texture; i++) {
		size_t len = 0;

		if (read(fd, &len, sizeof(size_t)) != sizeof(size_t))
			return (video->error = ERR_READ, false);
		if (len <= 0)
			return (video->error = ERR_INVALID_NUMBER, false);
		video->texture_name[i] = malloc(sizeof(char) * (len + 1));
		if (video->texture_name[i] == NULL)
			return (video->error = ERR_MALLOC, false);
		video->texture_name[i][len] = '\0';
		if (READ_FILE)
			return (video->error = ERR_READ, false);
	}
	return (true);
}

video_t video_create_from_fd(int fd)
{
	video_t video = video_create();

	if (!error_video(&video, fd) || !get_error_video(&video, fd))
		return (video);
	if (read(fd, &video.time, sizeof(size_t)) != sizeof(size_t)) {
		video.error = ERR_READ;
		return (video);
	}
	if (video.time <= 0) {
		video.error = ERR_INVALID_NUMBER;
		return (video);
	}
	return (video);
}
