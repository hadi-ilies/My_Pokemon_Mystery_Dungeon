/*
** EPITECH PROJECT, 2018
** adventure_intro_creae
** File description:
** adventure_intro_create
*/

#include "my.h"
#include <prototype.h>
#include "adventure_intro.h"

void ad_intro_destroy(intro_adventure_t *ad_intro)
{
	sfText_destroy(ad_intro->text);
	sfFont_destroy(ad_intro->font);
	sfRectangleShape_destroy(ad_intro->rect);
	sfTexture_destroy(ad_intro->texture[0]);
}

intro_adventure_t ad_intro_create(void)
{
	intro_adventure_t ad_intro;

	ad_intro.font = sfFont_createFromFile(FONT);
	ad_intro.text = sfText_create();
	ad_intro.rect = sfRectangleShape_create();
	sfRectangleShape_setSize(ad_intro.rect, (sfVector2f) {1920, 1080});
	sfRectangleShape_setPosition(ad_intro.rect, (sfVector2f) {0, 0});
	ad_intro.texture[0] = sfTexture_createFromFile(PICTURE1, NULL);
	ad_intro.texture[1] = sfTexture_createFromFile(END, NULL);
	sfText_setFont(ad_intro.text, ad_intro.font);
	return (ad_intro);
}
