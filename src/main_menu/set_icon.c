/*
** EPITECH PROJECT, 2017
** rpg
** File description:
** set_icon.c
*/

#include "prototype.h"

void set_icon(sfRenderWindow *window, char *file_name)
{
	static int i = 0;
	sfImage *image = sfImage_createFromFile(file_name);
	const sfUint8 *pixels;
	sfVector2u size;

	if (!image)
		return;
	pixels = sfImage_getPixelsPtr(image);
	size = sfImage_getSize(image);
	sfRenderWindow_setIcon(window, size.x, size.y, pixels);
	sfImage_destroy(image);
	if (i++ < 100)
		set_icon(window, file_name);
}
