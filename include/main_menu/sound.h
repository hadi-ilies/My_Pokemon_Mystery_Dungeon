/*
** EPITECH PROJECT, 2018
** sound.h
** File description:
** sound.h
*/

#pragma once

#include "prototype.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>

#define NB_SOUND_EFFECT 7
#define NB_MUSIC_EFFECT 3
#define ENTER_SOUND "resources/sound_effect/enter.wav"
#define RETURN_SOUND "resources/sound_effect/return.wav"
#define CLOSE_SOUND "resources/sound_effect/close.wav"
#define MYSTERY_SOUND "resources/sound_effect/mystery.wav"
#define TEXT_SOUND "resources/sound_effect/text.wav"
#define MAIN_SOUND "resources/music/pokemon_menu.ogg"
#define HOW_TO_PLAY_SONG "resources/music/black_clo.ogg"
#define MOVE_SOUND "resources/sound_effect/move_curs.wav"
#define INTRO_AD "resources/music/intro.ogg"
#define RIP_MUSIC "resources/music/rip.ogg"

typedef struct {
	sfMusic **sound_effect;
	sfMusic **music;
} sound_bank_t;
