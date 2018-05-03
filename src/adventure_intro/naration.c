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

void load_history_text(sfRenderWindow *window, intro_adventure_t *ad_intro)
{
	sfText_setPosition(ad_intro->text, (sfVector2f) {WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2});
	sfRenderWindow_drawText(window, ad_intro->text, NULL);
}

void insert_history_text(char *str, intro_adventure_t *ad_intro,
			int *i, bool test)
{
	char *str2 = "";
	char *string = my_strncat(str2, str, *i);

	sfText_setString(ad_intro->text, string);
	free(string);
	test == true ? (*i)++ : 0;
}

void display_history(sfRenderWindow *window, intro_adventure_t *ad_intro,
		size_t button)
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
	insert_history_text(str, ad_intro, &i, test);
	load_history_text(window, ad_intro);
}
