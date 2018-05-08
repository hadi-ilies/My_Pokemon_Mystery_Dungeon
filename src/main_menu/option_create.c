/*
** EPITECH PROJECT, 2018
** option_create
** File description:
** option_create
*/

#include <prototype.h>
#include "main_menu/menu.h"
#include "option_map_editor.h"
#include "main_menu/option_menu.h"

void create_option_choice(sfText *choice[3], sfFont *font)
{
	for (size_t i = 0; i < 3; i++) {
		choice[i] = sfText_create();
		sfText_setFont(choice[i], font);
	}
}

/*setting | setting call from there*/

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
