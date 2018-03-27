/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "my.h"

particle_tab_t particules_create(size_t size)
{
	particle_tab_t particules;

	particules.nb_particle = size;
	particules.particle = malloc(sizeof(particle_t) * particules.nb_particle);
	for (size_t i = 0; i < particules.nb_particle; i++) {
		particules.particle[i].rect = sfRectangleShape_create();
		particules.particle[i].texture = sfTexture_createFromFile(TEX_SMOKE, NULL);
		particules.particle[i].speed = (sfVector2f) {rand() % 11 - 5, (rand() % 300 + 30)};
		particules.particle[i].acc = (sfVector2f) {rand() % 10 / 10, rand() % 10 / 10};
	}
	return (particules);
}

sfRenderWindow *init(void)
{
	sfVideoMode mode = {1920, 1080, 32};
	sfRenderWindow *window;

	window = sfRenderWindow_create(mode, "Particules", sfClose, NULL);
	if (!window)
		return (NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

void particule_set_position(particle_tab_t *buffer, sfVector2f pos)
{
	for (size_t i = 0; i < buffer->nb_particle; i++) {
		sfRectangleShape_setSize(buffer->particle[i].rect, (sfVector2f) {64, 64});
		sfRectangleShape_setPosition(buffer->particle[i].rect, pos);
		sfRectangleShape_setTexture(buffer->particle[i].rect, buffer->particle[i].texture, sfTrue);
		sfRectangleShape_setTextureRect(buffer->particle[i].rect, (sfIntRect) {256 * (rand() % 6), 255 * (rand() % 6), 256, 255});
		sfRectangleShape_setOrigin(buffer->particle[i].rect, (sfVector2f) {32, 32});
		pos = (sfVector2f) {rand() % 30 + 1920 / 2 + 15, rand() % 30 + 1080};
	}
}

void drawPartBuffer(particle_tab_t *this, sfRenderWindow *window)
{
	for (size_t i = 0; i < this->nb_particle; i++) {
		sfColor color = sfRectangleShape_getFillColor(this->particle[i].rect);

		sfRectangleShape_move(this->particle[i].rect, this->particle[i].speed);
		this->particle[i].speed.x += this->particle[i].acc.x;
		this->particle[i].speed.y += this->particle[i].acc.y;
		sfRenderWindow_drawRectangleShape(window, this->particle[i].rect, NULL);
		if (color.a > 0) {
			color.a -= 2;
			sfRectangleShape_setFillColor(this->particle[i].rect, color);
		}
	}
}

void update(sfRenderWindow *window, particle_tab_t *buffer)
{
	sfRenderWindow_clear(window, sfBlack);
	drawPartBuffer(buffer, window);
	sfRenderWindow_display(window);
}

void for_fun(particle_tab_t *buf, sfRenderWindow *window)
{
	sfColor color = {255, 255, 255, 255};

	for (size_t i = 0; i < buf->nb_particle; i++)
		if (sfRectangleShape_getPosition(buf->particle[i].rect).y > 1080 && rand() & 2) {
			sfRectangleShape_setPosition(buf->particle[i].rect, (sfVector2f) {rand() % 31 - 15 + sfMouse_getPositionRenderWindow(window).x, rand() % 31 - 15 + sfMouse_getPositionRenderWindow(window).y});
			buf->particle[i].speed = (sfVector2f) {rand() % 11, -(rand() % 10 + 5)};
			sfRectangleShape_setFillColor(buf->particle[i].rect, color);
		}
}

int main (void)
{
	particle_tab_t buffer = particules_create(200);
	sfRenderWindow *window = init();
	sfEvent event;

	sfRenderWindow_clear(window, sfWhite);
	particule_set_position(&buffer, (sfVector2f) {100, 200});
	while(sfRenderWindow_isOpen(window)) {
		while(sfRenderWindow_pollEvent(window, &event)) {
			if(event.type==sfEvtClosed) {
				sfRenderWindow_close(window);
				return(0);
			}
		}
		for_fun(&buffer, window);
		update(window, &buffer);
	}
	return(0);
}
