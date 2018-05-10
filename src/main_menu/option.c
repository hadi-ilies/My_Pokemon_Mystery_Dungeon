/*
** EPITECH PROJECT, 2018
** option
** File description:
** option
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "option_map_editor.h"
#include "main_menu/option_menu.h"

void display_options(option_t *option, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, option->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, option->back, NULL);
	option_choice_cursor(option, window);
	sfRenderWindow_drawText(window,
			option->window_size[option->nb_tile], NULL);
	sfRenderWindow_drawText(window, option->sound_value[0], NULL);
	sfRenderWindow_drawText(window, option->sound_value[1], NULL);
}

void option_menu(sfRenderWindow *window, sfEvent *event, menu_t *menu)
{
	option_t option = option_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, event)) {
			if (evt_close(event, window)) {
				settings_save(&menu->settings, CONFIG);
				return;
			}
			option_move_cursor(&option, event);
			change_win_size(&option, event, window);
			resize_win(window, &option);
			sound_volume(event, window, &option, menu);
			music_volume(event, window, &option, menu);
		}
		sfRenderWindow_clear(window, sfBlack);
		display_options(&option, window);
		sfRenderWindow_display(window);
	}
}
