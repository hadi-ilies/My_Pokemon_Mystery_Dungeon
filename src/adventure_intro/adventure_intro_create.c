/*
** EPITECH PROJECT, 2018
** adventure_intro_creae
** File description:
** adventure_intro_create
*/

#include "my.h"
#include <prototype.h>
#include "adventure_intro.h"
#include "macro.h"

void ad_intro_destroy(intro_adventure_t *ad_intro)
{
	sfText_destroy(ad_intro->text);
	sfFont_destroy(ad_intro->font);
	sfRectangleShape_destroy(ad_intro->rect);
	sfTexture_destroy(ad_intro->texture[0]);
}

intro_adventure_t ad_end_create(void)
{
	intro_adventure_t ad_end;

	ad_end.font = sfFont_createFromFile(FONT);
	ad_end.text = sfText_create();
	ad_end.rect = sfRectangleShape_create();
	sfRectangleShape_setSize(ad_end.rect, V2F(1920, 1080));
	sfRectangleShape_setPosition(ad_end.rect, V2F(0, 0));
	ad_end.texture[0] = sfTexture_createFromFile(END_PIC, NULL);
	ad_end.texture[1] = sfTexture_createFromFile(END, NULL);
	sfText_setFont(ad_end.text, ad_end.font);
	ad_end.history = false;
	return (ad_end);
}

intro_adventure_t ad_intro_create(void)
{
	intro_adventure_t ad_intro;

	ad_intro.font = sfFont_createFromFile(FONT);
	ad_intro.text = sfText_create();
	ad_intro.rect = sfRectangleShape_create();
	sfRectangleShape_setSize(ad_intro.rect, V2F(1920, 1080));
	sfRectangleShape_setPosition(ad_intro.rect, V2F(0, 0));
	ad_intro.texture[0] = sfTexture_createFromFile(PICTURE1, NULL);
	ad_intro.texture[1] = sfTexture_createFromFile(PICTURE2, NULL);
	ad_intro.texture[2] = sfTexture_createFromFile(PICTURE3, NULL);
	ad_intro.texture[3] = sfTexture_createFromFile(PICTURE4, NULL);
	ad_intro.texture[4] = sfTexture_createFromFile(PICTURE3, NULL);
	ad_intro.texture[5] = sfTexture_createFromFile(PICTURE2, NULL);
	sfText_setFont(ad_intro.text, ad_intro.font);
	ad_intro.history = true;
	return (ad_intro);
}
