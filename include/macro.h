/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** macro.h
*/

#ifndef MACRO_H_
#define MACRO_H_

#define BACK_MAP "resources/texture/map_editor/background_map_editor.jpg"
#define MUSIC_EDITOR "resources/texture/map_editor/OstMapEditor.ogg"
#define WINDOW_SIZE sfRenderWindow_getSize(window)
#define MOUSE_POS sfMouse_getPositionRenderWindow(window)
#define RECT_MOUSE (sfFloatRect) {MOUSE_POS.x + 20, MOUSE_POS.y + 20, 40, 40}
#define GET_MAP_X MOUSE_POS.x / map->size.x + map->pos.x + 0.5 \
	- (WINDOW_SIZE.x / 2) / map->size.x
#define GET_MAP_Y MOUSE_POS.y / map->size.y + map->pos.y + 0.5 \
	- (WINDOW_SIZE.y / 2) / map->size.y

#endif
