/*
** EPITECH PROJECT, 2018
** menu
** File description:
** menu
*/

#define BACK "resources/texture/menu/back/1.png"
#define FONT "resources/font/pokemon_char.ttf"
#define ITEM "titre.png"
#define NB_BUTTON 6
#define BACK_OPTION "resources/texture/menu/option.png"
#define NB_BUTTON_EDITOR 5
#define BACK_MENU_EDITOR "resources/texture/map_editor/back.jpg"
#define CURSOR_EDITOR "resources/texture/map_editor/cursor.png"

typedef struct {
	sfRectangleShape *rect[4];
	sfText *text[NB_BUTTON];
	sfFont *font;
	size_t button;
} menu_t;

menu_t menu_create(void);
size_t move_curseur(menu_t *menu, sfEvent *event);
void set_icon(sfRenderWindow *window, char *file_name);
void display_menu(sfRenderWindow *window, menu_t *menu, loading_t *back);
void display_texte_button(sfRenderWindow *window, menu_t *menu);
void destroy_all(loading_t *back, sfRenderWindow *window, menu_t *menu);
