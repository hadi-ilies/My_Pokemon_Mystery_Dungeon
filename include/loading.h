/*
** EPITECH PROJECT, 2018
** loading
** File description:
** loading
*/

#ifndef LOADING_H_
#define LOADING_H_

#include "prototype.h"
#define LOAD "resources/texture/chargement.jpg"
#define PRESS_KEY "resources/texture/press_key.png"
typedef struct {
	sfSprite *sprite;
	sfTexture *texture;
} loading_t;
#endif
