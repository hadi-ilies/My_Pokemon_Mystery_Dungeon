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

void load_editor_loop(menu_t *menu, map_t *map, sfRenderWindow *window);
void screen_and_back_destroy(sfRectangleShape *back, sfSprite *screen);
void move_map(sfVector2f *pos);
void zoom_map(sfEvent *event, map_t *map);
bool hit_point_rect(sfVector2i *point, sfFloatRect *rect);
back_and_music_t optional_create(void);
loading_t back_editor_create(sfRenderWindow *window);
menu_t menu_editor_create(sfMusic **sound_effect);
void text_editor(menu_t *menu);
void pages_editor(menu_t *menu);
size_t move_curseur_editor(menu_t *menu, sfEvent *event);
void trans_cursor_editor(menu_t *menu, int *tmp1, int *tmp2);
bool enter_editor(sfRenderWindow *window, menu_t *menu,
		sfEvent *event, map_t *map);
void menu_map_editor_menu(sfRenderWindow *window, sfMusic **sound_effect);
void trans_cursor_editor(menu_t *menu, int *tmp1, int *tmp2);
size_t move_curseur_editor(menu_t *menu, sfEvent *event);
void display_menu_editor(sfRenderWindow *window, menu_t *menu, loading_t *back);
size_t count_file(char *path);
char **take_filename(char *path);
void new_map(menu_t *menu, map_t *map, sfRenderWindow *window);
int load_the_map(map_t *map, tile_map_t *tile_map);
void menu_save_map(map_t *map, sfRenderWindow *window);
void manage_map(sfEvent *event, sfRenderWindow *window,
		map_t *map, tva_t *mouse_tva);
void insert_to_map(tile_map_t *tile_map, tva_t *tva, tva_t mouse_tva);
void linking_rooms(map_t *map);
bool isit_on_inventory(map_t *map, sfRenderWindow *window);
void play_your_map(sfRenderWindow *window, map_t *map);
#endif
