/*
** EPITECH PROJECT, 2018
** menu_create
** File description:
** menu_create
*/

#include "prototype.h"
#include "macro.h"
#include "main_menu/sound.h"
#include "main_menu/menu.h"

void pages(menu_t *menu)
{
	for (int i = 0; i < 3; i++) {
		menu->rect[i] = sfRectangleShape_create();
		sfRectangleShape_setFillColor(menu->rect[i],
					(sfColor) {0, 0, 0, 150});
		sfRectangleShape_setOutlineThickness(menu->rect[i], 10);
		sfRectangleShape_setOutlineColor(menu->rect[i], sfRed);
	}
	sfRectangleShape_setSize(menu->rect[0], (sfVector2f) {400, 620});
	sfRectangleShape_setPosition(menu->rect[0], (sfVector2f) {10, 10});
	sfRectangleShape_setSize(menu->rect[1], (sfVector2f) {400, 400});
	sfRectangleShape_setPosition(menu->rect[1],
				(sfVector2f) {1920 - 410, 10});
	sfRectangleShape_setSize(menu->rect[2], (sfVector2f) {1100, 200});
	sfRectangleShape_setPosition(menu->rect[2], (sfVector2f) {400, 750});
	menu->rect[3] = sfRectangleShape_create();
	sfRectangleShape_setSize(menu->rect[3], (sfVector2f) {400, 100});
	sfRectangleShape_setFillColor(menu->rect[3], (sfColor) {0, 0, 0, 150});
	sfRectangleShape_setOutlineThickness(menu->rect[3], 3);
	sfRectangleShape_setOutlineColor(menu->rect[3], sfYellow);
}

void text(menu_t *menu)
{
	menu->font = sfFont_createFromFile(FONT);
	for (int i = 0; i < NB_BUTTON; i++)
		menu->text[i] = sfText_create();
}

sfMusic **sound_effect_create(void)
{
	sfMusic **sound_effect = malloc(sizeof(sound_effect) * NB_SOUND_EFFECT);

	if (sound_effect == NULL)
		return (NULL);
	sound_effect[0] = sfMusic_createFromFile(ENTER_SOUND);
	sound_effect[1] = sfMusic_createFromFile(RETURN_SOUND);
	sound_effect[2] = sfMusic_createFromFile(CLOSE_SOUND);
	sound_effect[3] = sfMusic_createFromFile(MYSTERY_SOUND);
	sound_effect[4] = sfMusic_createFromFile(TEXT_SOUND);
	sound_effect[5] = sfMusic_createFromFile(MOVE_SOUND);
	sound_effect[6] = sfMusic_createFromFile(MAIN_SOUND);
	sfMusic_play(sound_effect[2]);
	sfMusic_pause(sound_effect[2]);
	return (sound_effect);
}

sfMusic **music_effect_create(void)
{
	sfMusic **music_effect = malloc(sizeof(music_effect) * NB_MUSIC_EFFECT);

	if (music_effect == NULL)
		return (NULL);
	music_effect[0] = sfMusic_createFromFile(HOW_TO_PLAY_SONG);
	music_effect[1] = sfMusic_createFromFile(INTRO_AD);
	return (music_effect);
}

menu_t menu_create(void)
{
	menu_t menu;

	pages(&menu);
	text(&menu);
	menu.button = 0;
	menu.tile_map = NULL;
	menu.settings = settings_load(CONFIG);
	menu.sound.sound_effect = sound_effect_create();
	menu.sound.music = music_effect_create();
	return (menu);
}
