/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** game_pause.c
*/

#include "prototype.h"
#include "game_resource.h"

static bool manage_key(sfEvent *event, size_t *pos)
{
	if (event->key.code == sfKeyUp)
		if (*pos > 0)
			*pos -= 1;
	if (event->key.code == sfKeyDown)
		if (*pos + 1 < 2)
			*pos += 1;
	if (event->key.code == sfKeySpace || event->key.code == sfKeyReturn)
		return (true);
	return (false);
}

static bool manage_event(sfRenderWindow *window, size_t *pos)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event)) {
		if (evt_close(&event, window)) {
			*pos = 0;
			return (true);
		}
		if (event.type == sfEvtKeyPressed && manage_key(&event, pos))
			return (true);
	}
	return (false);
}

static void aff(sfRenderWindow *window)
{
	sfVector2u wis = sfRenderWindow_getSize(window);
	sfTexture *texture = sfTexture_createFromFile(STAT_RECT, NULL);
	sfRectangleShape *rectangle = sfRectangleShape_create();
	const sfVector2f size = {500, 500};
	const sfVector2f pos = {wis.x / 2 - size.x / 2, wis.y / 2 - size.y / 2};
	const sfColor color = {100, 100, 255, 255};

	if (texture == NULL || rectangle == NULL)
		return;
	sfRectangleShape_setTexture(rectangle, texture, sfTrue);
	sfRectangleShape_setSize(rectangle, size);
	sfRectangleShape_setPosition(rectangle, pos);
	sfRectangleShape_setFillColor(rectangle, color);
	sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
	sfTexture_destroy(texture);
	sfRectangleShape_destroy(rectangle);
}

static void text_aff(sfRenderWindow *window, size_t curs)
{
	sfVector2u wis = sfRenderWindow_getSize(window);
	sfFont *font = sfFont_createFromFile(GAME_FONT);
	sfText *text = sfText_create();
	const sfVector2f size = {500, 500};
	const sfVector2f pos = {wis.x / 2 - size.x / 2, wis.y / 2 - size.y / 2};
	sfVector2f pos2 = {pos.x + size.x / 4, pos.y + size.y / 3 - 30 / 2};

	if (font == NULL || text == NULL)
		return;

	sfText_setFont(text, font);
	sfText_setString(text, (!curs ? "> Resume" : "  Resume"));
	sfText_setPosition(text, pos2);
	sfRenderWindow_drawText(window, text, NULL);
	pos2.y += size.y / 3;
	sfText_setString(text, (curs ? "> Rage Quit" : "  Rage Quit"));
	sfText_setPosition(text, pos2);
	sfRenderWindow_drawText(window, text, NULL);
	sfFont_destroy(font);
	sfText_destroy(text);
}

bool game_pause(sfRenderWindow *window, garou_t *garou)
{
	(void)garou;
	for (size_t pos = 0; sfRenderWindow_isOpen(window);) {
		if (manage_event(window, &pos))
			return (pos);
		aff(window);
		text_aff(window, pos);
		sfRenderWindow_display(window);
	}
	return (false);
}
