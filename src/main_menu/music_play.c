/*
** EPITECH PROJECT, 2018
** music
** File description:
** music
*/

#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "settings.h"

void music_play(sfMusic *sound)
{
	sfMusic_play(sound);
	sfMusic_setLoop(sound, sfTrue);
}
