/*
** EPITECH PROJECT, 2018
** game_over
** File description:
** game_over
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "settings.h"
#include "adventure_intro.h"

void destroy_game_over(sfSprite *sprite, sfTexture *texture, menu_t *menu)
{
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
	sfMusic_play(menu->sound.sound_effect[6]);
}

void game_over(sfRenderWindow *window, menu_t *menu)
{
	sfEvent event;
	sfSprite *sprit = sfSprite_create();
	sfTexture *texture = sfTexture_createFromFile(RIP, NULL);
	size_t i = 0;

	sfMusic_play(menu->sound.music[2]);
	sfSprite_setTexture(sprit, texture, sfTrue);
	sfSprite_setPosition(sprit, V2F(0, 0));
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (evt_close(&event, window)) {
				destroy_game_over(sprit, texture, menu);
				return;
			}
		}
		i < 255 ? sfSprite_setColor(sprit, COL(255, 255, 255, i++)) : 0;
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprit, NULL);
		sfRenderWindow_display(window);
	}
}
