/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** manage_keys.c
*/

#include "prototype.h"

static void manage_num_r(anime_tab_t *anime_tab,
			 size_t *anime_num, size_t *rectex_num)
{
	if (sfKeyboard_isKeyPressed(sfKeyP))
		if (*rectex_num > 0) {
			anime_t anime = anime_tab->anime[*anime_num];
			bool cond = !anime.rectex[*rectex_num].rect.width;

			cond ? anime_tab->anime[*anime_num].nb_rectex-- : 0;
			*rectex_num -= 1;
		}
	if (sfKeyboard_isKeyPressed(sfKeyN)) {
		if (*rectex_num >= anime_tab->anime[*anime_num].nb_rectex - 1)
			add_rectex(&anime_tab->anime[*anime_num]);
		*rectex_num += 1;
	}
}

static void manage_num_a(anime_tab_t *anime_tab,
			 size_t *anime_num, size_t *rectex_num)
{
	if (sfKeyboard_isKeyPressed(sfKeyBack))
		if (*anime_num > 0) {
			anime_t anime = anime_tab->anime[*anime_num];

			!anime.rectex[0].rect.width ? anime_tab->nb_anime-- : 0;
			*anime_num -= 1;
		}
	if (sfKeyboard_isKeyPressed(sfKeyReturn))
		if (*anime_num < anime_tab->nb_anime - 1)
			*anime_num += 1;
	if (*rectex_num >= anime_tab->anime[*anime_num].nb_rectex)
		*rectex_num = 0;
}

static void manage_rectex(rectex_t *rectex)
{
	bool cond = sfKeyboard_isKeyPressed(sfKeyLShift);

	if (cond || sfKeyboard_isKeyPressed(sfKeyRShift)) {
		sfKeyboard_isKeyPressed(sfKeyLeft) ? rectex->rect.width-- : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? rectex->rect.width++ : 0;
		sfKeyboard_isKeyPressed(sfKeyUp) ? rectex->rect.height-- : 0;
		sfKeyboard_isKeyPressed(sfKeyDown) ? rectex->rect.height++ : 0;
	}
	else {
		sfKeyboard_isKeyPressed(sfKeyLeft) ? rectex->rect.left-- : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? rectex->rect.left++ : 0;
		sfKeyboard_isKeyPressed(sfKeyUp) ? rectex->rect.top-- : 0;
		sfKeyboard_isKeyPressed(sfKeyDown) ? rectex->rect.top++ : 0;
	}
	if (cond && sfKeyboard_isKeyPressed(sfKeyRShift)) {
		if (rectex->rect.width > rectex->rect.height)
			rectex->rect.height = rectex->rect.width;
		if (rectex->rect.height > rectex->rect.width)
			rectex->rect.width = rectex->rect.height;
	}
}

static void manage_rectex2(anime_tab_t *anime_tab, rectex_t *rectex,
			size_t *anime_num, size_t *rectex_num)
{
	if (sfKeyboard_isKeyPressed(sfKeyEqual)) {
		if (*rectex_num > 0) {
			anime_t anime = anime_tab->anime[*anime_num];
			size_t num = *rectex_num - 1;

			rectex->rect.width = anime.rectex[num].rect.width;
			rectex->rect.height = anime.rectex[num].rect.height;
		}
		else if (*anime_num > 0) {
			anime_t anime = anime_tab->anime[*anime_num - 1];

			rectex->rect.width = anime.rectex[0].rect.width;
			rectex->rect.height = anime.rectex[0].rect.height;
		}
	}
}

void manage_keys(rectex_t *rectex, anime_tab_t *anime_tab,
	size_t *anime_num, size_t *rectex_num)
{
	manage_rectex(rectex);
	manage_rectex2(anime_tab, rectex, anime_num, rectex_num);
	manage_num_r(anime_tab, anime_num, rectex_num);
	manage_num_a(anime_tab, anime_num, rectex_num);
	anime_tab->num = *anime_num;
	rectex = &anime_tab->anime[*anime_num].rectex[*rectex_num];
}
