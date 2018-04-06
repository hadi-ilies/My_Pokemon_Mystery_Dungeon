/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** macro.h
*/

#ifndef MACRO_H_
#define MACRO_H_

#define TOOL_SIZE 100
#define TOOL_DIST 200
#define POS_SIZE_SHAPE (sfVector2f){TOOL_SIZE + 20, TOOL_SIZE + 20}
#define WIN_REC (sfFloatRect) {1920 / 2, 1080 / 2, 1920, 1080}
#define ANIME_START_FILE "intro_files/anime_start"
#define ANIME_INTRO_FILE "intro_files/intro_anime"
#define MUSIC_INTRO "resources/music/pokemon-theme.ogg"
#define SOUND_START "resources/music/Sound_intro.ogg"
#define BACK_MAP "resources/texture/map_editor/background_map_editor.jpg"
#define MUSIC_EDITOR "resources/texture/map_editor/OstMapEditor.ogg"
#define PIX rect.left - rect.width / 2 - 10
#define PIY  rect.top - rect.height / 2 - 10
#define WINDOW_SIZE sfRenderWindow_getSize(window)
#define MOUSE_POS sfMouse_getPositionRenderWindow(window)
#define RECT_MOUSE (sfFloatRect) {MOUSE_POS.x + 20, MOUSE_POS.y + 20, 40, 40}
#define GET_MAP_X MOUSE_POS.x / map->size.x + map->pos.x + 0.5 \
	- (WINDOW_SIZE.x / 2) / map->size.x
#define GET_MAP_Y MOUSE_POS.y / map->size.y + map->pos.y + 0.5 \
	- (WINDOW_SIZE.y / 2) / map->size.y

#endif
