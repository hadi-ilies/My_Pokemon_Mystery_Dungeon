/*
** EPITECH PROJECT, 2018
** option
** File description:
** option
*/

#pragma once

#include <SFML/Graphics.h>
#include <prototype.h>
#include <my.h>

typedef struct {
	sfText *choice[3];
	size_t choice_curs;
	sfText *window_size[3];
	sfText *sound_value[3];
	sfFont *font;
	sfSprite *screen;
	sfRectangleShape *back;
	size_t nb_tile;
	size_t size_x;
	size_t size_y;
} option_t;

void music_volume(sfEvent *event, sfRenderWindow *window,
		option_t *option, menu_t *menu);
void sound_volume(sfEvent *event, sfRenderWindow *window,
		option_t *option, menu_t *menu);
void change_win_size(option_t *option, sfEvent *event, sfRenderWindow *window);
void resize_win(sfRenderWindow *window, option_t *option);
void insert_win_size(sfText *win_size[3]);
void create_option_choice(sfText *choice[3], sfFont *font);
option_t option_create(sfRenderWindow *window);
void option_choice_cursor(option_t *option, sfRenderWindow *window);
void option_move_cursor(option_t *option, sfEvent *event);
