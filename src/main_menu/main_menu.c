/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** main_menu.c
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "settings.h"
#include "adventure_intro.h"

loading_t back_create(void)
{
	loading_t optional;

	optional.sprite = sfSprite_create();
	optional.texture = sfTexture_createFromFile(BACK, NULL);
	back_create_icon(&optional);
	sfSprite_setTexture(optional.sprite, optional.texture, sfTrue);
	sfRectangleShape_setTexture(optional.icon_back, optional.texture_icon,
				sfTrue);
	return (optional);
}

void enter(sfRenderWindow *window, menu_t *menu, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyReturn) {
		sfMusic_play(menu->sound.sound_effect[0]);
		if (menu->button == 0) {
			adventure_intro(window, menu);
			GAME_COND;
		} if (menu->button == 1)
			menu_map_editor_menu(window, menu->sound.sound_effect);
		if (menu->button == 2)
			anime_editor_menu(window);
		if (menu->button == 3)
			option_menu(window, event, menu);
		if (menu->button == 4)
			credit_menu(window, event);
		if (menu->button == 5)
			sfMusic_play(menu->sound.sound_effect[2]);
	}
}

void open_window_menu(sfRenderWindow *window, menu_t *menu, loading_t *back)
{
	move_curseur(menu, NULL);
	sfRenderWindow_clear(window, sfBlack);
	display_menu(window, menu, back);
	sfRenderWindow_display(window);
	if (sfMusic_getStatus(menu->sound.sound_effect[2]) == sfStopped)
		sfRenderWindow_close(window);
}

void event_loop_menu(sfEvent *event, menu_t *menu, sfRenderWindow *window)
{
	while (sfRenderWindow_pollEvent(window, event)) {
		evt_close(event, window);
		menu->button = move_curseur(menu, event);
		enter(window, menu, event);
	}
}

int main_menu(sfRenderWindow *window)
{
	loading_t back = back_create();
	menu_t menu = menu_create();
	sfEvent event = {.type = sfEvtJoystickButtonPressed};

	if (!menu.sound.sound_effect || !menu.sound.music || !back.texture)
		return (84);
	main_intro(window, &event);
	for (int i = 0; i < NB_BUTTON; i++)
		sfText_setFont(menu.text[i], menu.font);
	music_play(menu.sound.sound_effect[6]);
	while (sfRenderWindow_isOpen(window)) {
		event_loop_menu(&event, &menu, window);
		open_window_menu(window, &menu, &back);
	}
	return (destroy_all(&back, window, &menu), 0);
}
