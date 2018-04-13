/*
** EPITECH PROJECT, 2018
** text
** File description:
** text
*/
#include "prototype.h"
#include <string.h> // tmp
#include "main_menu/menu.h"

char *text_button(menu_t *menu)
{
	char *str;

	if (menu->button == 0)
		str = "Start a new adventure in the PokeWorld !\n";
	if (menu->button == 1)
		str = "Create Your own map";
	if (menu->button == 2)
		str = "Create your own animation";
	if (menu->button == 3)
		str ="Settings";
	if (menu->button == 4)
		str = "who is the best programmer";
	if (menu->button == 5)
		str = "are You Sure you wanna Go ?";
	return (str);
}

void load_text(sfRenderWindow *window, sfText *text)
{
	sfText_setPosition(text, (sfVector2f) {420, 760});
	sfText_setColor(text, (sfColor){250, 250, 0, 200});
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
}

void display_texte_button(sfRenderWindow *window, menu_t *menu)
{
	sfFont *font = sfFont_createFromFile(FONT);
	sfText *text = sfText_create();
	static int i = 1;
	static bool test = true;
	static size_t button = 0;
	char *str2 = "";
	char *str = text_button(menu);

	sfText_setFont(text, font);
	if (str[i] == '\0' && test == true) {
		button = menu->button;
		test = false;
	} if (button != menu->button) {
		i = 1;
		test = true;
		button = menu->button;
	}
	sfText_setString(text, concat_n(str2, str, i));
	test == true ? i++ : 0;
	load_text(window, text);
}
