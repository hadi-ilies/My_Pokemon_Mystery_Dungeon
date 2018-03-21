/*
** EPITECH PROJECT, 2017
** for_norme
** File description:
** image.h
*/

#ifndef IMAGE_H_
#define IMAGE_H_

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct {
	sfTexture *texture;
	sfSprite *sprite;
} image_t;

image_t image_create(char *file_name);
void image_destroy(image_t *image);
bool image_error(image_t *image);

#endif
