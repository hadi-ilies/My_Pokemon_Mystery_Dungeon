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

void option_choice_cursor(option_t *option, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;

	sfText_setString(option->choice[0], "WINDOW RESOLUTION");
	sfText_setString(option->choice[1], "GAME VOLUME");
	sfText_setString(option->choice[2], "SOUND VOLUME");
	for (size_t i = 0; i < 3; i++) {
		sfText_setPosition(option->choice[i], (sfVector2f) {WINDOW_SIZE.x / 2 - 300, pos_y});
		sfText_setColor(option->choice[i], (sfColor){250, 250, 0,
					option->choice_curs == i ? 255 : 180});
		sfRenderWindow_drawText(window, option->choice[i], NULL);
		pos_y += 100;
	}
}

void display_options(option_t *option, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, option->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, option->back, NULL);
	option_choice_cursor(option, window);
	sfRenderWindow_drawText(window, option->window_size[option->nb_tile], NULL);
	sfRenderWindow_drawText(window, option->sound_value[0], NULL);
	sfRenderWindow_drawText(window, option->sound_value[1], NULL);
}

void create_option_choice(sfText *choice[3], sfFont *font)
{
	for (size_t i = 0; i < 3; i++) {
		choice[i] = sfText_create();
		sfText_setFont(choice[i], font);
	}
}

void insert_win_size(sfText *win_size[3])
{
	sfText_setString(win_size[0], "800 X 600");
	sfText_setString(win_size[1], "1600 X 1200");
	sfText_setString(win_size[2], "1920 X 1080");
}

option_t option_create(sfRenderWindow *window)
{
	option_t option;

	option.font = sfFont_createFromFile(FONT);
	create_option_choice(option.choice, option.font);
	create_option_choice(option.window_size, option.font);
	create_option_choice(option.sound_value, option.font);
	insert_win_size(option.window_size);
	option.screen = create_screen_param(window);
	option.back = create_back_param(window);
	option.size_x = 1920;
	option.size_y = 1080;
	option.choice_curs = 0;
	option.nb_tile = 0;
	return (option);
}

void option_move_cursor(option_t *option, sfEvent *event)
{
	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp)
		&& option->choice_curs > 0) {
			option->choice_curs--;
		} if (sfKeyboard_isKeyPressed(sfKeyDown)
		&& option->choice_curs <  2) {
			option->choice_curs++;
		}
	}
}

void change_win_size(option_t *option, sfEvent *event, sfRenderWindow *window)
{
	if (option->choice_curs == 0) {
		if (option->nb_tile < 2 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight)
			option->nb_tile++;
		if (option->nb_tile > 0 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft)
			option->nb_tile--;
	}
	sfText_setPosition(option->window_size[option->nb_tile],
			(sfVector2f) {WINDOW_SIZE.x / 2 + 50, WINDOW_SIZE.y / 2 - 300});
}

void music_volume(sfEvent *event,
		  sfRenderWindow *window, option_t *option, menu_t *menu)
{
	char *str;

	if (option->choice_curs == 1) {
		if (menu->settings.music_volume < 100 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight) {
			menu->settings.music_volume++;
		} if (menu->settings.music_volume > 0 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft) {
			menu->settings.music_volume--;
		}
	}
	str = inttostr((int)menu->settings.music_volume);
	sfText_setString(option->sound_value[0], str);
	sfText_setPosition(option->sound_value[0],
			(sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2 - 200});
}

void sound_volume(sfEvent *event,
		  sfRenderWindow *window, option_t *option, menu_t *menu)
{
	char *str;

	if (option->choice_curs == 2) {
		if (menu->settings.sound_volume < 100 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyRight) {
			menu->settings.sound_volume++;
		} if (menu->settings.sound_volume > 0 && event->type == sfEvtKeyPressed
		&& event->key.code == sfKeyLeft) {
			menu->settings.sound_volume--;
		}
	}
	str = inttostr((int)menu->settings.sound_volume);
	sfText_setString(option->sound_value[1], str);
	sfText_setPosition(option->sound_value[1],
			(sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2 - 100});
}

void resize_win(sfRenderWindow *window, option_t *option)
{
	if (option->choice_curs == 0) {
		char **size = my_str_to_tab(
			sfText_getString(option->window_size[option->nb_tile]), "X");
		//printf("%s\n", sfText_getString(option->window_size[option->nb_tile]));
		//printf("%d|%d\n", atoi(size[0]), atoi(size[1]));
		sfRenderWindow_setSize(window, (sfVector2u) {atoi(size[0]), atoi(size[1])});
	}
}

void option_menu(sfRenderWindow *window, sfEvent *event, menu_t *menu)
{
	option_t option = option_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
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
