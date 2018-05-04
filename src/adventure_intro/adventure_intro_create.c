/*
** EPITECH PROJECT, 2018
** adventure_intro_creae
** File description:
** adventure_intro_create
*/

#include "my.h"
#include <prototype.h>
#include "adventure_intro.h"

intro_adventure_t ad_intro_create(void)
{
	intro_adventure_t ad_intro;

	ad_intro.font = sfFont_createFromFile(FONT);
	ad_intro.text = sfText_create();
	ad_intro.rect = sfRectangleShape_create();
	sfRectangleShape_setSize(ad_intro.rect, (sfVector2f) {1920, 1080});
	sfRectangleShape_setPosition(ad_intro.rect, (sfVector2f) {0, 0});
	ad_intro.texture = sfTexture_createFromFile(PICTURE1, NULL);
	sfText_setFont(ad_intro.text, ad_intro.font);
	return (ad_intro);
}
