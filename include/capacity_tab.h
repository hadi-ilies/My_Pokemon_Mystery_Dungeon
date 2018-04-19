/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** capacity_tab.h
*/

#ifndef CAPACITY_TAB_H_
#define CAPACITY_TAB_H_

#include "capacity.h"
#include "type.h"

static capacity_t capacity_tab[] = {
	{"Tackle", TYPE_NORMAL, PHYSICAL, 40, 100, 35},
	{"Aqua Tail", TYPE_WATER, PHYSICAL, 90, 90, 10},
	{"Cut", TYPE_NORMAL, PHYSICAL, 50, 95, 30},
	{"Dragon Claw", TYPE_DRAGON, PHYSICAL, 80, 100, 15},
	{"Dragon Hammer", TYPE_DRAGON, PHYSICAL, 90, 100, 15},
	{"Dragon Pulse", TYPE_DRAGON, SPECIAL, 85, 100, 10},
	{"Drill Peck", TYPE_FLYING, PHYSICAL, 80, 100, 20},
	{"Egg Bomb", TYPE_NORMAL, PHYSICAL, 100, 75, 10},
	{"Fairy Wind", TYPE_FAIRY, SPECIAL, 40, 100, 30},
	{"High Horsepower", TYPE_GROUND, PHYSICAL, 95, 95, 10},
	{"Horn Attack", TYPE_NORMAL, PHYSICAL, 65, 100, 25},
	{"Hydro Pump", TYPE_WATER, PHYSICAL, 110, 80, 5},
	{"Leafage", TYPE_GRASS, PHYSICAL, 40, 100, 40},
	{"Megahorn", TYPE_GRASS, PHYSICAL, 120, 85, 10},
	{NULL, TYPE_NULL, 0, 0, 0, 0}
};

#endif
