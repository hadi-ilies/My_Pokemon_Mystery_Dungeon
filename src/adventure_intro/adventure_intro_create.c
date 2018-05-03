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
	sfText_setFont(ad_intro.text, ad_intro.font);
	return (ad_intro);
}
