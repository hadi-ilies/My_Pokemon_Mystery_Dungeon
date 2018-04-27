/*
** EPITECH PROJECT, 2018
** create win
** File description:
** create win
*/

#include "prototype.h"
#include "macro.h"

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

sfRenderWindow *window_create(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (window == NULL)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	set_icon(window, ICON);
	return (window);
}
