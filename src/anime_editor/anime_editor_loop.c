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

static void rectex_set_size(rectex_t *rectex, sfRenderWindow *window, sfSprite *sprite)
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

static void aff(sfRenderWindow *window, sfSprite *sprite,
	 sfRectangleShape *rect, anime_tab_t *anime_tab)
{
	sfRenderWindow_clear(window, COL(50, 50, 50, 255));
	sfRenderWindow_drawSprite(window, sprite, NULL);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	anime_tab_aff(window, anime_tab, FR(1500, 400, 500, 500));
	sfRenderWindow_display(window);
}

static void set_up(sfRectangleShape *rect, sfSprite *sprite,
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

static void rect_update(sfRectangleShape *rect, rectex_t *rectex, sfSprite *sprite)
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
			set_rectex_pos(&event, window, &RECTEX, sprite);
			if (event.type == sfEvtKeyPressed)
				manage_keys(&RECTEX, anime_tab, nums);
		}
		rectex_set_size(&RECTEX, window, sprite);
		rect_update(rect, &RECTEX, sprite);
		aff(window, sprite, rect, anime_tab);
	}
	sfRectangleShape_destroy(rect);
	sfSprite_destroy(sprite);
}
