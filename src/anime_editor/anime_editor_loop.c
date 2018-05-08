/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** anime_game_loop.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"
#include "macro.h"

sfFloatRect get_sprite_rect(sfSprite *sprite)
{
	sfFloatRect sprite_rect = sfSprite_getGlobalBounds(sprite);
	sfFloatRect rect_sub = sfSprite_getLocalBounds(sprite);

	sprite_rect.width /= rect_sub.width;
	sprite_rect.height /= rect_sub.height;
	return (sprite_rect);
}

void zoom(sfEvent *event, sfSprite *sprite)
{
	sfFloatRect sprite_rect = get_sprite_rect(sprite);

	if (event->type == sfEvtMouseWheelScrolled) {
		sprite_rect.width += event->mouseWheelScroll.delta;
		if (sprite_rect.width <= 1)
			sprite_rect.width = 1;
		if (sprite_rect.width >= 100)
			sprite_rect.width = 100;
		sprite_rect.height = sprite_rect.width;
	}
	sfSprite_setPosition(sprite, V2F(sprite_rect.left, sprite_rect.top));
	sfSprite_setScale(sprite, V2F(sprite_rect.width, sprite_rect.height));
}

void set_rectex_pos(sfEvent *event, sfRenderWindow *window,
		    rectex_t *rectex, sfSprite *sprite)
{
	sfFloatRect sprite_rect = get_sprite_rect(sprite);

	if (event->type == sfEvtMouseButtonPressed)
		if (sfMouse_isButtonPressed(sfMouseLeft)) {
			rectex->rect.left = (MOUSE_POS.x - sprite_rect.left);
			rectex->rect.top = (MOUSE_POS.y - sprite_rect.top);
			rectex->rect.left /= sprite_rect.width;
			rectex->rect.top /= sprite_rect.height;
			rectex->rect.width = 0;
			rectex->rect.height = 0;
		}
}

void sprite_move(sfEvent *event, sfRenderWindow *window,
		 sfSprite *sprite)
{
	sfFloatRect sprite_rect = get_sprite_rect(sprite);

	if (event->type == sfEvtMouseMoved) {
		if (MOUSE_POS.x < 10)
			sprite_rect.left += 10;
		if (MOUSE_POS.y < 10)
			sprite_rect.top += 10;
		if (MOUSE_POS.x >= (int)WINDOW_SIZE.x - 10)
			sprite_rect.left -= 10;
		if (MOUSE_POS.y >= (int)WINDOW_SIZE.y - 10)
			sprite_rect.top -= 10;
	}
	sfSprite_setPosition(sprite, V2F(sprite_rect.left, sprite_rect.top));
}

void add_rectex(anime_t *anime)
{
	rectex_t *rectex = malloc(sizeof(rectex_t) * (anime->nb_rectex + 1));

	if (rectex == NULL)
		return;
	for (size_t i = 0; i < anime->nb_rectex; i++)
		rectex[i] = anime->rectex[i];
	rectex[anime->nb_rectex] = (rectex_t){0, {0, 0, 0, 0}};
	free(anime->rectex);
	anime->rectex = rectex;
	anime->nb_rectex++;
}

void manage_num_r(anime_tab_t *anime_tab, size_t *anime_num, size_t *rectex_num)
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

void manage_num_a(anime_tab_t *anime_tab, size_t *anime_num, size_t *rectex_num)
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

void manage_rectex(rectex_t *rectex)
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

void manage_rectex2(anime_tab_t *anime_tab, rectex_t *rectex,
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

void rectex_set_size(rectex_t *rectex, sfRenderWindow *window, sfSprite *sprite)
{
	sfFloatRect sprite_rect = get_sprite_rect(sprite);

	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		rectex->rect.width = MOUSE_POS.x - sprite_rect.left;
		rectex->rect.width /= sprite_rect.width;
		rectex->rect.width -= rectex->rect.left;
		rectex->rect.height = MOUSE_POS.y - sprite_rect.top;
		rectex->rect.height /= sprite_rect.height;
		rectex->rect.height -= rectex->rect.top;
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

void aff(sfRenderWindow *window, sfSprite *sprite,
	 sfRectangleShape *rect, anime_tab_t *anime_tab)
{
	sfRenderWindow_clear(window, COL(50, 50, 50, 255));
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	anime_tab_aff(window, anime_tab, FR(1500, 400, 500, 500));
	sfRenderWindow_display(window);
}

void set_up(sfRectangleShape *rect, sfSprite *sprite,
	    anime_tab_t *anime_tab, rectex_t *rectex)
{
	sfIntRect sprite_rect = {0, 0, 10, 10};
	size_t num = rectex->texture_num;

	sfRectangleShape_setFillColor(rect, sfTransparent);
	sfRectangleShape_setOutlineColor(rect, sfRed);
	sfSprite_setTexture(sprite, anime_tab->texname[num].texture, sfTrue);
	sfSprite_setPosition(sprite, V2F(sprite_rect.left, sprite_rect.top));
	sfSprite_setScale(sprite, V2F(sprite_rect.width, sprite_rect.height));
}

void rect_update(sfRectangleShape *rect, rectex_t *rectex, sfSprite *sprite)
{
	sfFloatRect sprite_rect = get_sprite_rect(sprite);
	sfVector2f pos = {rectex->rect.left, rectex->rect.top};
	sfVector2f size = {rectex->rect.width, rectex->rect.height};

	pos.x = pos.x * sprite_rect.width + sprite_rect.left;
	pos.y = pos.y * sprite_rect.height + sprite_rect.top;
	size.x *= sprite_rect.width;
	size.y *= sprite_rect.height;
	sfRectangleShape_setOutlineThickness(rect, sprite_rect.width);
	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setSize(rect, size);
}

void anime_editor_loop(sfRenderWindow *window, anime_tab_t *anime_tab)
{
	sfSprite *sprite = sfSprite_create();
	sfRectangleShape *rect = sfRectangleShape_create();
	sfEvent event;
	size_t anime_num = 0;
	size_t rectex_num = 0;

	set_up(rect, sprite, anime_tab, &RECTEX);
	for (bool exit = false; sfRenderWindow_isOpen(window) && !exit;) {
		while (sfRenderWindow_pollEvent(window, &event)) {
			!exit ? exit = evt_close(&event, window) : 0;
			zoom(&event, sprite);
			set_rectex_pos(&event, window, &RECTEX, sprite);
			sprite_move(&event, window, sprite);
			if (event.type == sfEvtKeyPressed)
				manage_keys(&RECTEX, anime_tab, &anime_num, &rectex_num);
		}
		rectex_set_size(&RECTEX, window, sprite);
		rect_update(rect, &RECTEX, sprite);
		aff(window, sprite, rect, anime_tab);
	}
	sfRectangleShape_destroy(rect);
	sfSprite_destroy(sprite);
}
