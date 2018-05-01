/*
** EPITECH PROJECT, 2018
** graphic
** File description:
** graphic_write
*/

#include <stdbool.h>
#include <stdio.h>
#include "my.h"
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "map_editor_save.h"

char *add_letter(char *str, char c)
{
	char *new_str;
	size_t len = 2;

	if (str != NULL)
		len += my_strlen(str);
	new_str = malloc(sizeof(char) * len);
	if (new_str == NULL)
		return (str);
	if (str != NULL)
		my_strncpy(new_str, str, my_strlen(str));
	new_str[len - 2] = c;
	new_str[len - 1] = '\0';
	free(str);
	return (new_str);
}

char *supr_last_letter(char *str)
{
	str[my_strlen(str) - 1] = '\0';
	return (str);
}

void write_func(sfEvent *event, save_editor_t *save)
{
	for (sfKeyCode i = sfKeyA; i <= sfKeyZ; i++)
		if (event->key.code == i)
			save->name_file =
			add_letter(save->name_file, i + 'a');
	for (sfKeyCode i = sfKeyNum0; i <= sfKeyNum9; i++)
		if (event->key.code == i)
			save->name_file =
			add_letter(save->name_file, i - sfKeyNum0 + '0');
	if (event->key.code == sfKeySpace)
		save->name_file = add_letter(save->name_file, ' ');
	for (sfKeyCode i = sfKeyNumpad0; i <= sfKeyNumpad9; i++)
		if (event->key.code == i)
			save->name_file =
			add_letter(save->name_file, i - sfKeyNumpad0 + '0');
}

void write_name(sfEvent *event, save_editor_t *save)
{
	if (event->type == sfEvtKeyPressed) {
		if (my_strlen(save->name_file) < 20)
			write_func(event, save);
		if (event->key.code == sfKeyBack)
			if (save->name_file != NULL
			&& save->name_file[0] != '\0')
			save->name_file = supr_last_letter(save->name_file);
	}
}
