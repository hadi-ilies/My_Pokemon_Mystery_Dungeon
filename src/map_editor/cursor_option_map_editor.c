/*
** EPITECH PROJECT, 2018
** curs
** File description:
** curs
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

void move_curseur_option_editor(option_editor_t *option, sfEvent *event)
{
	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp)
		&& option->choice_curs > 0) {
			option->choice_curs--;
		} if (sfKeyboard_isKeyPressed(sfKeyDown)
		&& option->choice_curs < 2) {
			option->choice_curs++;
		}
	}
}
