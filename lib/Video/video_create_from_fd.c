/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** video_create_from_fd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "video.h"

video_t video_create_from_fd(int fd)
{
	video_t video = video_create();

	if (video.error != VIDEO_OK)
		return (video);
	if (read(fd, &video.nb_texture, sizeof(size_t)) != sizeof(size_t)) {
		video.error = VIDEO_READ;
		return (video);
	}
	if (video.nb_texture <= 0) {
		video.error = VIDEO_INVALID_NUMBER;
		return (video);
	}
	video.texture_name = malloc(sizeof(char *) * video.nb_texture);
	if (video.texture_name == NULL) {
		video.error = VIDEO_MALLOC;
		return (video);
	}
	for (size_t i = 0; i < video.nb_texture; i++) {
		size_t len = 0;

		if (read(fd, &len, sizeof(size_t)) != sizeof(size_t)) {
			video.error = VIDEO_READ;
			return (video);
		}
		if (len <= 0) {
			video.error = VIDEO_INVALID_NUMBER;
			return (video);
		}
		video.texture_name[i] = malloc(sizeof(char) * (len + 1));
		if (video.texture_name[i] == NULL) {
			video.error = VIDEO_MALLOC;
			return (video);
		}
		video.texture_name[i][len] = '\0';
		if (read(fd, video.texture_name[i], sizeof(char) * len) != (int)(sizeof(char) * len)) {
			video.error = VIDEO_READ;
			return (video);
		}
	}
	if (read(fd, &video.time, sizeof(size_t)) != sizeof(size_t)) {
		video.error = VIDEO_READ;
		return (video);
	}
	if (video.time <= 0) {
		video.error = VIDEO_INVALID_NUMBER;
		return (video);
	}
	return (video);
}
