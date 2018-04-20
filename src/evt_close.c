/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** evt_close.c
*/

#include "prototype.h"

void evt_close(sfEvent *event, sfRenderWindow *window)
{
	if (event->type == sfEvtClosed)
		sfRenderWindow_close(window);
}
