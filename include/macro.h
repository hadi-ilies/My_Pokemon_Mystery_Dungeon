/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** macro.h
*/

#ifndef MACRO_H_
#define MACRO_H_

#define V2F(x, y) (sfVector2f){x, y}
#define V2I(x, y) (sfVector2i){x, y}
#define V2U(x, y) (sfVector2u){x, y}
#define COL(r, g, b, a) (sfColor){r, g, b, a}
#define FR(left, top, width, height) (sfFloatRect){left, top, width, height}
#define ICON "resources/texture/icon.png"
#define TOOL_SIZE 100
#define TOOL_DIST 200
#define POS_SIZE_SHAPE (sfVector2f){TOOL_SIZE + 20, TOOL_SIZE + 20}
#define ANIME_START_FILE "intro_files/anime_start"
#define ANIME_INTRO_FILE "intro_files/intro_anime"
#define MUSIC_INTRO "resources/music/pokemon-theme.ogg"
#define SOUND_START "resources/sound_effect/Sound_intro.ogg"
#define BACK_MAP "resources/texture/map_editor/background_map_editor.jpg"
#define MUSIC_EDITOR "resources/texture/map_editor/OstMapEditor.ogg"
#define COND_AFF sfRenderWindow_drawRectangleShape(window, rect, NULL)
#define COND_TRANS sfRectangleShape_setFillColor(rect, (sfColor) {255, 255, \
		255, trans < 20 ? trans = 255 : (trans--)})
#define COND_WIDTH sfRectangleShape_setSize(rect, (sfVector2f) {size_w == 800 \
				? size_w = 400 : (size_w++), size_h})
#define PIX rect.left - rect.width / 2 - 10
#define PIY rect.top - rect.height / 2 - 10
#define WINDOW_SIZE sfRenderWindow_getSize(window)
#define WIN_REC (sfFloatRect) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2, \
			WINDOW_SIZE.x, WINDOW_SIZE.y}
#define MOUSE_POS sfMouse_getPositionRenderWindow(window)
#define RECT_MOUSE (sfFloatRect) {MOUSE_POS.x + 20, MOUSE_POS.y + 20, 40, 40}
#define GET_MAP_X MOUSE_POS.x / map->size.x + map->pos.x + 0.5 \
	- (WINDOW_SIZE.x / 2) / map->size.x
#define GET_MAP_Y MOUSE_POS.y / map->size.y + map->pos.y + 0.5 \
	- (WINDOW_SIZE.y / 2) / map->size.y

#define PLAY_YOUR_MAP_WITH_G (event->type == sfEvtKeyPressed \
			&& event->key.code == sfKeyG)
#define LINK_ROOMS_WITH_P (event->type == sfEvtKeyPressed && \
			event->key.code == sfKeyP) ? linking_rooms(map) : 0
#define CLEAN_MAP_WITH_C (event->type == sfEvtKeyPressed && \
			event->key.code == sfKeyC) ? clean_map(map) : 0
#define PATH_MAP_COND map->tab[(cor->x + size_x)][(cor->y + size_y)].type
#define EXIT (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
#define ENTER_COND event.type == sfEvtKeyPressed && event.key.code ==sfKeyReturn
#define GET_STRING sfText_getString(load->text[load->text_curs])
#define GET_STRING_SIZE sfText_getString(option->window_size[option->nb_tile]);
#define TILE_MAP "resources/tile_map"
#define MAPS "resources/maps"
#define CONFIG "resources/config"
#define SIZE_T sizeof(size_t)
#define RECTEX_T sizeof(rectex_t)
#define TRANS_RECT_COND i < 255 ? sfRectangleShape_setFillColor(ad_intro->rect,\
					(sfColor) {255, 255, 255, i++}) : 0
#define CHECKMAP (size_t) cor->y + size_y < map->nb_case_y
#define RIP "resources/texture/rip.png"
#define GAME_COND game_menu(window) == 0 ? game_over(window, menu)\
		: adventure_end(window, menu)
#define LEVEL garou->dungeon.entity[0].level + level_diff + garou->\
	dungeon.stage_num / 2
#define LIFE STAT(garou->dungeon.entity[i], life)
#define POSITION rand_pos_ground(&garou->dungeon.map)
#define STEPS garou->dungeon.stage_num < garou->dungeon.nb_stage
#endif
