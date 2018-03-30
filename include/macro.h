/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** macro.h
*/

#ifndef MACRO_H_
#define MACRO_H_

#define WINDOW_SIZE sfRenderWindow_getSize(window)
#define MOUSE_POS sfMouse_getPositionRenderWindow(window)
#define RECT_MOUSE (sfFloatRect) {MOUSE_POS.x + 20, MOUSE_POS.y + 20, 40, 40}

#endif
