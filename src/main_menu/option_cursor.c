/*
** EPITECH PROJECT, 2018
** option_cursor
** File description:
** option_cursor
*/

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
		sfText_setPosition(option->choice[i],
		V2F(WINDOW_SIZE.x / 2 - 300, pos_y));
		sfText_setColor(option->choice[i],
		COL(250, 250, 0, option->choice_curs == i ? 255 : 180));
		sfRenderWindow_drawText(window, option->choice[i], NULL);
		pos_y += 100;
	}
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
