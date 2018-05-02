/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** video_create_from_file.c
*/

#include <fcntl.h>
#include "video.h"

video_t video_create_from_file(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	video_t video;

	if (fd == -1) {
		video.error = VIDEO_OPEN;
		return (video);
	}
	video = video_create_from_fd(fd);
	return (video);
}
