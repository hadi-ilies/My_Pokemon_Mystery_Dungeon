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

loading_t loading_create(sfRenderWindow *window)
{
	loading_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(LOAD, NULL);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	sfRenderWindow_drawSprite(window, optional.sprite, NULL);
	sfRenderWindow_display(window);
	return (optional);
}

sfRenderWindow *window_create(void)
{
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "my_rpg", WINDOW_PARAMS, NULL);
	if (window == NULL)
		return (NULL);
	loading_t load = loading_create(window);

	sfRenderWindow_setFramerateLimit(window, FRAMERATE_LIMIT);
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	set_icon(window, ICON);
	sfSprite_destroy(load.sprite);
	sfTexture_destroy(load.texture);
	return (window);
}
