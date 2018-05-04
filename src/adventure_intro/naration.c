/*
** EPITECH PROJECT, 2018
** naration
** File description:
** naration
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "adventure_intro.h"

char *text_history(size_t button)
{
	char *str;

	if (button == 0)
		str = "once upon the time in the pokeworld gabou and hisddd!\n";
	if (button == 1)
		str = "Abso goes in the caca pipi caca pipi caca prout zizid\n";
	if (button == 2)
		str = "hey bitchies how are you today am your fucking father\n";
	if (button == 3)
		str ="zertyuiolkhgfghkigfghjkifdfghjkjhgfghjkjvgfcvgnhj,knhg\n";
	if (button == 4)
		str = "foufoufificacacazizizbouobvoudqdklqhsdkqhdkjqfdeiujsd\n";
	if (button == 5)
		str = "zertyukilkjkdkohdlksqhdoqkjdlksqudlksqdjsqldjlksqjdlk\n";
	return (str);
}

void load_history_text(sfRenderWindow *window, intro_adventure_t *ad_intro,
		size_t len)
{
	sfText_setPosition(ad_intro->text,
	(sfVector2f) {WINDOW_SIZE.x / len, 20});
	sfRenderWindow_drawText(window, ad_intro->text, NULL);
}

size_t insert_history_text(char *str, intro_adventure_t *ad_intro,
			int *i, bool test)
{
	char *str2 = "";
	char *string = my_strncat(str2, str, *i);
	size_t len = my_strlen(string);

	sfText_setString(ad_intro->text, string);
	free(string);
	test == true ? (*i)++ : 0;
	return (len);
}

void display_history(sfRenderWindow *window, intro_adventure_t *ad_intro,
		size_t button, menu_t *menu)
{
	static int i = 1;
	static bool test = true;
	static size_t tmp = 0;
	char *str = text_history(button);

	(str[i] == '\0') ? test = false : 0;
	if (tmp != button) {
		test = true;
		tmp = button;
		i = 1;
	}
	size_t len = insert_history_text(str, ad_intro, &i, test);

	test == false ? sfMusic_stop(menu->sound.sound_effect[4]) : 0;
	len % 3 == 0 && test == true ?
		sfMusic_play(menu->sound.sound_effect[4]) : 0;
	load_history_text(window, ad_intro, len);
}
