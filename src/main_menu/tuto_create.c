/*
** EPITECH PROJECT, 2018
** tuto
** File description:
** tuto
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "adventure_intro.h"
#include "how_to_play.h"

how_to_play_t create_tuto(sfRenderWindow *window)
{
	(void) window;
	how_to_play_t tuto;

	tuto.page = 0;
	tuto.tex = true;
	tuto.img = sfSprite_create();
	tuto.textu[0] = sfTexture_createFromFile(TUTO1, NULL);
	tuto.textu[1] = sfTexture_createFromFile(TUTO2, NULL);
	tuto.textu[2] = sfTexture_createFromFile(TUTO3, NULL);
	tuto.textu[3] = sfTexture_createFromFile(TUTO4, NULL);
	return (tuto);
}
