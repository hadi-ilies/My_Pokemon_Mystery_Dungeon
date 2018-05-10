/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** prototype.h
*/

#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "game_resource.h"
#include "loading.h"
#include "main_menu/menu.h"
#include "video.h"

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_BITS_PER_PIXEL 32
#define WINDOW_PARAMS sfFullscreen
#define FRAMERATE_LIMIT 30
#define WINDOW_NAME "My_pokemon_mystery_dungeons (Pokemon fan game)"

int main_menu(sfRenderWindow *window);
sfRenderWindow *window_create(void);
void destroy_factories(anime_tab_t *animation, sfMusic *music[3],
		       video_t *video);
int destroy_and_check_error_anime(anime_tab_t *animation, video_t *video);
void music_create(sfMusic *music[3]);
void get_start(anime_tab_t *animation, sfMusic *music[3],
	       sfRenderWindow *window, video_t *video);
loading_t loading_create(sfRenderWindow *window);
void destroy_music(sfMusic *music[3]);
int game_menu(sfRenderWindow *window);
int map_editor_menu(sfRenderWindow *window);
int anime_editor_menu(sfRenderWindow *window);
void anime_tab_save(anime_tab_t *anime_tab, char *file_name);
int game_loop(sfRenderWindow *window, garou_t *garou);
int map_editor_loop(sfRenderWindow *window, map_t *map);
void anime_editor_loop(sfRenderWindow *window, anime_tab_t *anime_tab);
bool evt_close(sfEvent *event, sfRenderWindow *window);
int main_intro(sfRenderWindow *window, sfEvent *event);
int error_anime(video_t video);
void credit_menu(sfRenderWindow *window, sfEvent *event);
void option_menu(sfRenderWindow *window, sfEvent *event, menu_t *menu);
void swap_alt(tile_map_t *tile_map, tva_t *tva);
void pick_tile(sfRenderWindow *window, sfFloatRect rect,
	       tva_t tva, tva_t *mouse_tva);
void display_tools(sfRenderWindow *window, map_t *map, tva_t *mouse_tva);
void refresh_map(sfEvent *event, map_t *map);
bool dont_touch_borders(map_t *map, size_t x, size_t y);
bool insert_water_loop(map_t *map);
void set_rectex_pos(sfEvent *event, sfRenderWindow *window,
		    rectex_t *rectex, sfSprite *sprite);
sfFloatRect get_sprite_rect(sfSprite *sprite);
void add_rectex(anime_t *anime);
void manage_keys(rectex_t *rectex, anime_tab_t *anime_tab,
		 size_t *anime_num, size_t *rectex_num);

#endif
