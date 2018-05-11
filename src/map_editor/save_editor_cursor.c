/*
** EPITECH PROJECT, 2018
** cursor map editor
** File description:
** cursor map editor
*/

#include <stdbool.h>
#include <stdio.h>
#include "my.h"
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_save.h"

void choice_cursor_save(save_editor_t *save, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;

	sfText_setString(save->text[0], "NAME");
	sfText_setString(save->text[1], "OK");
	for (int i = 0; i < 2; i++) {
		sfText_setPosition(save->text[i],
		V2F(WINDOW_SIZE.x / 2 - 300, pos_y));
		sfText_setColor(save->text[i],
		COL(250, 250, 0, save->choice_curs == i ? 255 : 180));
		sfRenderWindow_drawText(window, save->text[i], NULL);
		pos_y += 100;
	}
}

void move_curseur_save_editor(save_editor_t *save, sfEvent *event)
{
	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp)
		&& save->choice_curs > 0)
			save->choice_curs--;
		if (sfKeyboard_isKeyPressed(sfKeyDown)
		&& save->choice_curs < 1)
			save->choice_curs++;
	}
}
