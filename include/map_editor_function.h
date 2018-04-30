/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** map_editor_function.h
*/

#ifndef MAP_EDITOR_FUNCTION_H_
#define MAP_EDITOR_FUNCTION_H_

#include "prototype.h"
#include "main_menu/menu.h"

typedef struct {
	sfSprite *sprite;
	sfTexture *texture;
	sfMusic *music;
} back_and_music_t;

void move_map(sfVector2f *pos);
void zoom_map(sfEvent *event, map_t *map);
bool hit_point_rect(sfVector2i *point, sfFloatRect *rect);
back_and_music_t optional_create(void);
loading_t back_editor_create(sfRenderWindow *window);
menu_t menu_editor_create(void);
void text_editor(menu_t *menu);
void pages_editor(menu_t *menu);
size_t move_curseur_editor(menu_t *menu, sfEvent *event);
void trans_cursor_editor(menu_t *menu, int *tmp1, int *tmp2);
bool enter_editor(sfRenderWindow *window, menu_t *menu,
		sfEvent *event, map_t *map);
void menu_map_editor_menu(sfRenderWindow *window);
void trans_cursor_editor(menu_t *menu, int *tmp1, int *tmp2);
size_t move_curseur_editor(menu_t *menu, sfEvent *event);
void menu_map_editor_menu(sfRenderWindow *window);
void display_menu_editor(sfRenderWindow *window, menu_t *menu, loading_t *back);
size_t count_file(char *path);
char **take_filename(char *path);
void new_map(menu_t *menu, map_t *map, sfRenderWindow *window);
int load_the_map(map_t *map, tile_map_t *tile_map);
void menu_save_map(map_t *map, sfRenderWindow *window);
void manage_map(sfEvent *event, sfRenderWindow *window,
		map_t *map, tva_t *mouse_tva);
void insert_to_map(tile_map_t *tile_map, tva_t *tva, tva_t mouse_tva);

#endif
