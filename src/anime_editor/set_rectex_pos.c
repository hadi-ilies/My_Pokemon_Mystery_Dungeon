/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** set_rectex_pos.c
*/

#include "prototype.h"
#include "macro.h"

static void zoom(sfEvent *event, sfSprite *sprite)
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

static void sprite_move(sfEvent *event, sfRenderWindow *window,
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

void set_rectex_pos(sfEvent *event, sfRenderWindow *window,
		rectex_t *rectex, sfSprite *sprite)
{
	sfFloatRect sprite_rect = get_sprite_rect(sprite);

	zoom(event, sprite);
	sprite_move(event, window, sprite);
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
