/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** player.c
*/

#include "game_resource.h"
#include "capacity_tab.h"
#include "input.h"

static size_t use_item(entity_t *entity, enum item_e inventory[INVENTORY_SIZE])
{
	size_t max = 0;

	for (size_t i = 1; i < 4; i++)
		if (PP_LOST(*entity, i) > PP_LOST(*entity, max))
			max = i;
	if (inventory[0] == ORAN_BERRY) {
		entity->life += 20;
		if (entity->life > STAT(*entity, life))
			entity->life = STAT(*entity, life);
	}
	if (inventory[0] == MAX_ELIXIR) {
		entity->pp[max] += 10;
		if (entity->pp[max] > CAPACITY(*entity, max).pp)
			entity->pp[max] = CAPACITY(*entity, max).pp;
	}
	inventory[0] = NONE;
	return (WAIT);
}

static size_t move(settings_t *settings)
{
	size_t input = 0;

	if (sfKeyboard_isKeyPressed(settings->key[KEY_LEFT]))
		input |= LEFT;
	if (sfKeyboard_isKeyPressed(settings->key[KEY_RIGHT]))
		input |= RIGHT;
	if (sfKeyboard_isKeyPressed(settings->key[KEY_UP]))
		input |= UP;
	if (sfKeyboard_isKeyPressed(settings->key[KEY_DOWN]))
		input |= DOWN;
	return (input);
}

static size_t attack(settings_t *settings, sfEvent *event)
{
	size_t input = 0;

	if (event && event->type == sfEvtKeyPressed) {
		if (event->key.code == settings->key[KEY_UP])
			input |= ATTACK | CAPACITY1;
		if (event->key.code == settings->key[KEY_LEFT])
			input |= ATTACK | CAPACITY2;
		if (event->key.code == settings->key[KEY_RIGHT])
			input |= ATTACK | CAPACITY3;
		if (event->key.code == settings->key[KEY_DOWN])
			input |= ATTACK | CAPACITY4;
	}
	return (input);
}

size_t player(entity_t *entity, garou_t *garou, sfEvent *event)
{
	size_t input = 0;

	if (sfKeyboard_isKeyPressed(garou->settings.key[KEY_ATTACK]))
		input |= attack(&garou->settings, event);
	else {
		input |= move(&garou->settings);
		if (!sfKeyboard_isKeyPressed(garou->settings.key[KEY_MOVE]))
			input |= (input ? MOVE : 0);
	}
	if (event && event->type == sfEvtKeyPressed)
		if (event->key.code == garou->settings.key[KEY_WAIT])
			input |= WAIT;
	if (event && event->type == sfEvtKeyPressed)
		if (event->key.code == sfKeyM && garou->inventory[0] != NONE)
			return (use_item(entity, garou->inventory));
	return (input);
}
