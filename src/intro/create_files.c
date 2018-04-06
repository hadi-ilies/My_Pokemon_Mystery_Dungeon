/*
** EPITECH PROJECT, 2018
** create_files
** File description:
** create_files
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "anime_tab.h"
#include "prototype.h"
#include "loading.h"
#include "video.h"
#include "macro.h"

void create_file_anime(void)
{
	int fd = creat("intro_anime", S_IRWXU); //open
	size_t n1 = 1;
	size_t nb = 763;
	size_t time = 10 * 1000000;

	write(fd, &nb, sizeof(size_t));
	for (size_t i = 82; i < nb + 82; i++) {
		char str[200] = {'\0'};
		size_t len = 0;

		sprintf(str, "resources/texture/intro_animation/teset-%.4d.png", i);
		len = strlen(str);
		write(fd, &len, sizeof(size_t));
		write(fd, str, len);
	}
	write(fd, &time, sizeof(size_t));
	close(fd);
}

void create_file_anime_start(void)
{
	int fd = creat("anime_start", S_IRWXU); //open
	size_t n1 = 1;
	size_t nb = 4;
	size_t st = 840;
	size_t time =  100000;

	write(fd, &nb, sizeof(size_t));
	for (size_t i = st; i < nb + st; i++) {
		char str[200] = {'\0'};
		size_t len = 0;

		sprintf(str, "resources/texture/intro_animation/teset-%.4d.png", i);
		len = strlen(str);
		write(fd, &len, sizeof(size_t));
		write(fd, str, len);
	}
	write(fd, &n1, sizeof(size_t));
	write(fd, &nb, sizeof(size_t));
	for (size_t i = 0; i < 4; i++) {
		rectex_t rect = {i, {0, 0, 1280, 720}};

		write(fd, &rect, sizeof(rectex_t));
	}
	write(fd, &time, sizeof(size_t));
	close(fd);
}
