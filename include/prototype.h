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
#include "video.h"
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080
#define WINDOW_BITS_PER_PIXEL 32
#define WINDOW_PARAMS sfClose
#define FRAMERATE_LIMIT 30

int main_menu(void);
void destroy_factories(anime_tab_t *animation, sfMusic *music[3],
		video_t *video);
int destroy_and_check_error_anime(anime_tab_t *animation, loading_t *load, video_t *video);
void music_create(sfMusic *music[3]);
void get_start(anime_tab_t *animation, sfMusic *music[3],
	       sfRenderWindow *window, video_t *video, sfEvent *event);
loading_t loading_create(sfRenderWindow *window);
void destroy_music(sfMusic *music[3]);
int game_menu(sfRenderWindow *window);
int map_editor_menu(sfRenderWindow *window);
int anime_editor_menu(sfRenderWindow *window);
int game_loop(sfRenderWindow *window, garou_t *garou);
int map_editor_loop(sfRenderWindow *window, map_t *map);
int anime_editor_loop(sfRenderWindow *window, anime_tab_t *anime_tab);
void evt_close(sfEvent *event, sfRenderWindow *window);
int main_intro(sfRenderWindow *window, sfEvent *event);
int error_anime(video_t video);
void credit_menu(sfRenderWindow *window, sfEvent *event);
void option_menu(sfRenderWindow *window, sfEvent *event);
void swap_alt(tile_map_t *tile_map, tva_t *tva);
void pick_tile(sfRenderWindow *window, sfFloatRect rect,
	tva_t tva, tva_t *mouse_tva);
void display_tools(sfRenderWindow *window, map_t *map, tva_t *mouse_tva);
void refresh_map(sfEvent *event, map_t *map);
bool dont_touch_borders(map_t *map, size_t x, size_t y);
#endif
