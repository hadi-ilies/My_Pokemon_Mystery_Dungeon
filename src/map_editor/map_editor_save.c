/*
** EPITECH PROJECT, 2018
** map_editor_save
** File description:
** map_editor_save
*/

#include <string.h>///tmp
#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_save.h"

void create_save_text(save_editor_t *save)
{
	save->font = sfFont_createFromFile(FONT);
	for (size_t i = 0; i < 4; i++) {
		save->text[i] = sfText_create();
		sfText_setFont(save->text[i], save->font);
	}
}

save_editor_t save_editor_create(sfRenderWindow *window)
{
	save_editor_t save;

	save.back = create_back_param(window);
	save.screen = create_screen_param(window);
	create_save_text(&save);
	save.choice_curs = 0;
	save.name_file = NULL;
	return (save);
}

void choice_cursor_save(save_editor_t *save, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;

	sfText_setString(save->text[0], "NAME");
	sfText_setString(save->text[1], "OK");
	for (size_t i = 0; i < 2; i++) {
		sfText_setPosition(save->text[i], (sfVector2f) {WINDOW_SIZE.x / 2 - 300, pos_y});
		sfText_setColor(save->text[i], (sfColor){250, 250, 0,
					save->choice_curs == i ? 255 : 180});
		sfRenderWindow_drawText(window, save->text[i], NULL);
		pos_y += 100;
	}
}

void display_save_editor(save_editor_t *save, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, save->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, save->back, NULL);
	choice_cursor_save(save, window);
	sfRenderWindow_drawText(window, save->text[3], NULL);
}

void move_curseur_save_editor(save_editor_t *save, sfRenderWindow *window,
			      sfEvent *event)
{
	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp)
		    && save->choice_curs > 0) {
			save->choice_curs--;
		} if (sfKeyboard_isKeyPressed(sfKeyDown)
		      && save->choice_curs <  2) {
			save->choice_curs++;
		}
	}
}

char *add_letter(char *str, char c)
{
	char *new_str;
	size_t len = 2;

	if (str != NULL)
		len += strlen(str);
	new_str = malloc(sizeof(char) * len);
	if (new_str == NULL)
		return (str);
	if (str != NULL)
		strcpy(new_str, str);
	new_str[len - 2] = c;
	new_str[len - 1] = '\0';
	free(str);
	return (new_str);
}

char *supr_last_letter(char *str)
{
	str[strlen(str) - 1] = '\0';
	return (str);
}

void write_func(sfEvent *event, save_editor_t *save)
{
	for (sfKeyCode i = sfKeyA; i <= sfKeyZ; i++)
		if (event->key.code == i)
			save->name_file = add_letter(save->name_file, i + 'a');
	for (sfKeyCode i = sfKeyNum0; i <= sfKeyNum9; i++)
		if (event->key.code == i)
			save->name_file = add_letter(save->name_file, i - sfKeyNum0 + '0');
	if (event->key.code == sfKeySpace)
		save->name_file = add_letter(save->name_file, ' ');
	for (sfKeyCode i = sfKeyNumpad0; i <= sfKeyNumpad9; i++)
		if (event->key.code == i)
			save->name_file = add_letter(save->name_file, i - sfKeyNumpad0 + '0');
}

void write_name(sfEvent *event, save_editor_t *save)
{
	if (event->type == sfEvtKeyPressed) {
		if (my_strlen(save->name_file) < 20)
			write_func(event, save);
		if (event->key.code == sfKeyBack)
			if (save->name_file != NULL && save->name_file[0] != '\0')
				save->name_file = supr_last_letter(save->name_file);
	}
}

void take_keyboard(save_editor_t *save, sfEvent *event, sfRenderWindow *window)
{
	if (save->choice_curs == 0) {
		write_name(event, save);
	}
	sfText_setString(save->text[3], save->name_file);
	sfText_setPosition(save->text[3],
			(sfVector2f) {WINDOW_SIZE.x / 2 - 150, WINDOW_SIZE.y / 2 - 300});
}

void ok_map(save_editor_t *save, sfEvent *event, map_t *map)
{
	char *str;

	if (save->choice_curs == 1 && event->type == sfEvtKeyPressed
	&& event->key.code == sfKeyReturn) {
		str = concat("resources/maps/", save->name_file);
		map_save(map, str);
	}
}

void menu_save_map(map_t *map, sfRenderWindow *window)
{
	sfEvent event;
	save_editor_t save = save_editor_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
			move_curseur_save_editor(&save, window, &event);
			take_keyboard(&save, &event, window);
			ok_map(&save, &event, map);
		}
		sfRenderWindow_clear(window, sfBlack);
		display_save_editor(&save, window);
		sfRenderWindow_display(window);
	}
}
