/*
** EPITECH PROJECT, 2018
** load
** File description:
** load
*/

#include <stdbool.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include "prototype.h"
#include "my.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"
#include "option_map_editor.h"
#include "load_maps_editor.h"

void load_choice_cursor(load_editor_t *load, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;

	for (size_t i = 0; i < 2; i++) {
		sfText_setPosition(load->choice[i],
		V2F(WINDOW_SIZE.x / 2 - 300, pos_y));
		sfText_setColor(load->choice[i],
		COL(250, 250, 0, load->choice_curs == i ? 255 : 180));
		sfRenderWindow_drawText(window, load->choice[i], NULL);
		pos_y += 100;
	}
}

void move_curseur_load_editor(load_editor_t *load, sfEvent *event)
{
	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp)
		&& load->choice_curs > 0) {
			load->choice_curs--;
		} if (sfKeyboard_isKeyPressed(sfKeyDown)
		&& load->choice_curs < 1) {
			load->choice_curs++;
		}
	}
}

void load_list_choice_cursor(load_editor_t *load, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;
	static size_t i = 5;
	size_t nb_file = count_file(MAPS);

	(load->text_curs > 0 && load->text_curs < i - 5) ? i -= 5 : 0;
	(load->text_curs == i) ? i += 5 : 0;
	(i >nb_file - 1) ? i = nb_file - 1 : 0;
	if (load->text_curs == nb_file - 1) {
		i = 5;
		load->text_curs = 0;
	} for (size_t j = i - 5; j < i; j++) {
		sfText_setPosition(load->text[j],
		V2F(WINDOW_SIZE.x / 2 + 500, pos_y));
		sfText_setColor(load->text[j],
		COL(250, 250, 0, load->text_curs == j ? 255 : 180));
		sfRenderWindow_drawText(window, load->text[j], NULL);
		pos_y += 100;
	}
}

void load_list_choice_min(load_editor_t *load, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;
	size_t nb_file = count_file(MAPS);

	for (size_t i = 0; i < nb_file; i++) {
		sfText_setPosition(load->text[i],
				(sfVector2f) {WINDOW_SIZE.x / 2 + 500, pos_y});
		sfText_setColor(load->text[i],
		COL(250, 250, 0, load->text_curs == i ? 255 : 180));
		sfRenderWindow_drawText(window, load->text[i], NULL);
		pos_y += 100;
	}
}

void move_curseur_load_list(load_editor_t *load, sfEvent *event)
{
	size_t nb_file = count_file(MAPS);

	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp)
		&& load->text_curs > 0) {
			load->text_curs--;
		} if (sfKeyboard_isKeyPressed(sfKeyDown)
		&& load->text_curs < nb_file - 1) {
			load->text_curs++;
		}
	}
}
