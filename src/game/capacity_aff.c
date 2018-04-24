/*
** EPITECH PROJECT, 2018
** my_rpy_2017
** File description:
** capacity_aff.c
*/

#include "game_resource.h"

char *get_pp(entity_t *entity, size_t capacity_num)
{
	char *str_pp = malloc(sizeof(char) * (2 + 1 + 2 + 1));
	size_t pp_max = entity->capacity[capacity_num]->pp;
	size_t pp = entity->pp[capacity_num];

	sprintf(str_pp, "%ld/%ld", pp, pp_max);
	return (str_pp);
}

void capacity_aff_rect(sfRenderWindow *window, sfVector2f pos, char *file_name)
{
	sfRectangleShape *rect = sfRectangleShape_create();
	sfVector2f size = {597, 179};
	sfTexture *texture = sfTexture_createFromFile(file_name, NULL);

	sfRectangleShape_setFillColor(rect, (sfColor){255, 255, 255, 200});
	sfRectangleShape_setSize(rect, size);
	sfRectangleShape_setPosition(rect, pos);
	sfRectangleShape_setTexture(rect, texture, sfTrue);
	sfRenderWindow_drawRectangleShape(window, rect, NULL);
	sfTexture_destroy(texture);
	sfRectangleShape_destroy(rect);
}

void capacity_aff_name(sfRenderWindow *window, garou_t *garou,
	     sfVector2f pos, size_t capacity_num)
{
	sfFont *font = sfFont_createFromFile(GAME_FONT);
	sfText *text = sfText_create();
	sfVector2f size = {597, 179};
	unsigned int text_size = size.y / 5;

	sfText_setFont(text, font);
	sfText_setColor(text, (sfColor){0, 0, 0, 200});
	sfText_setCharacterSize(text, text_size);
	pos.x += size.x / 4;
	pos.y += size.y / 3 - text_size / 2;
	sfText_setPosition(text, pos);
	sfText_setString(text, garou->entity[0].capacity[capacity_num]->name);
	sfRenderWindow_drawText(window, text, NULL);
	sfFont_destroy(font);
	sfText_destroy(text);
}

void capacity_aff_pp(sfRenderWindow *window, garou_t *garou,
	     sfVector2f pos, size_t capacity_num)
{
	sfFont *font = sfFont_createFromFile(GAME_FONT);
	sfText *text = sfText_create();
	sfVector2f size = {597, 179};
	unsigned int text_size = size.y / 5;
	char *str_pp = get_pp(&garou->entity[0], capacity_num);

	sfText_setFont(text, font);
	sfText_setColor(text, (sfColor){0, 0, 0, 200});
	sfText_setCharacterSize(text, text_size);
	pos.x += size.x / 4;
	pos.y += size.y / 3 - text_size / 2;
	pos = (sfVector2f){pos.x + size.x / 3, pos.y + text_size * 2};
	sfText_setPosition(text, pos);
	sfText_setString(text, str_pp);
	sfRenderWindow_drawText(window, text, NULL);
	sfFont_destroy(font);
	sfText_destroy(text);
	free(str_pp);
}

void capacity_aff(sfRenderWindow *window, garou_t *garou)
{
	sfVector2u win_size = sfRenderWindow_getSize(window);
	sfVector2f size = {597, 179};
	sfVector2f pos0 = {win_size.x / 2 - size.x / 2, win_size.y / 5};
	sfVector2f pos1 = {win_size.x / 4 - size.x / 2, 2 * win_size.y / 5};
	sfVector2f pos2 = {3 * win_size.x / 4 - size.x / 2, 2 * win_size.y / 5};
	sfVector2f pos3 = {win_size.x / 2 - size.x / 2, 3 * win_size.y / 5};

	capacity_aff_rect(window, pos0, CAPACITY_UP);
	capacity_aff_name(window, garou, pos0, 0);
	capacity_aff_pp(window, garou, pos0, 0);
	capacity_aff_rect(window, pos1, CAPACITY_LEFT);
	capacity_aff_name(window, garou, pos1, 1);
	capacity_aff_pp(window, garou, pos1, 1);
	capacity_aff_rect(window, pos2, CAPACITY_RIGHT);
	capacity_aff_name(window, garou, pos2, 2);
	capacity_aff_pp(window, garou, pos2, 2);
	capacity_aff_rect(window, pos3, CAPACITY_DOWN);
	capacity_aff_name(window, garou, pos3, 3);
	capacity_aff_pp(window, garou, pos3, 3);
}
