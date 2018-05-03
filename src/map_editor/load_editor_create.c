/*
** EPITECH PROJECT, 2018
** load
** File description:
** loadc _create
*/


#include "prototype.h"
#include "my.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_function.h"
#include "option_map_editor.h"
#include "load_maps_editor.h"

void insert_font_in_choice(load_editor_t *load)
{
	for (size_t i = 0; i < 2; i++) {
		load->choice[i] = sfText_create();
		sfText_setFont(load->choice[i], load->font);
	}
	sfText_setString(load->choice[0], "MAPS");
	sfText_setString(load->choice[1], "OK");
}

void load_editor_destroy(load_editor_t *load)
{
	sfRectangleShape_destroy(load->back);
	sfSprite_destroy(load->screen);
	sfFont_destroy(load->font);
	for (size_t i = 0; i < count_file(MAPS); i++)
		sfText_destroy(load->text[i]);
	free(load->text);
	for (size_t i = 0; i < 2; i++)
		sfText_destroy(load->choice[i]);
}

load_editor_t load_editor_create(sfRenderWindow *window)
{
	load_editor_t load;

	load.text = malloc(sizeof(sfText *) * count_file(MAPS));
	if (load.text == NULL)
		return (load);
	load.back = create_back_param(window);
	load.screen = create_screen_param(window);
	load.font = sfFont_createFromFile(FONT);
	insert_font_in_choice(&load);
	for (size_t i = 0; i < count_file(MAPS); i++) {
		load.text[i] = sfText_create();
		sfText_setFont(load.text[i], load.font);
	}
	load.choice_curs = 0;
	load.text_curs = 0;
	load.name_file = NULL;
	return (load);
}
