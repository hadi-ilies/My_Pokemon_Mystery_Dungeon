/*
** EPITECH PROJECT, 2018
** music_intro
** File description:
** music_intro
*/

#include <stdlib.h>
#include <stdio.h>
#include "anime_tab.h"
#include "prototype.h"
#include "loading.h"
#include "video.h"
#include "macro.h"

void music_create(sfMusic *music[3])
{
	music[0] = sfMusic_createFromFile(MUSIC_INTRO);
	music[1] = sfMusic_createFromFile(SOUND_START);
	sfMusic_play(music[0]);
	sfMusic_setLoop(music[0], sfTrue);
}

void destroy_music(sfMusic *music[3])
{
	sfMusic_destroy(music[0]);
	sfMusic_destroy(music[1]);
}
