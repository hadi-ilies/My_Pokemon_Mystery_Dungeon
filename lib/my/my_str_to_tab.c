/*
** EPITECH PROJECT, 2018
** lemin
** File description:
** get_words.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

bool in(char c, char *sep)
{
	if (c == '\0')
		return (true);
	for (size_t i = 0; sep[i] != '\0'; i++) {
		if (c == sep[i])
			return (true);
	}
	return (false);
}

size_t get_nb_words(char *command, char *sep)
{
	size_t nb_words = 0;

	if (command[0] == '\0')
		return (0);
	!in(command[0], sep) ? nb_words++ : 0;
	for (size_t i = 1; command[i] != '\0'; i++) {
		if (in(command[i - 1], sep) && !in(command[i], sep))
			nb_words++;
	}
	return (nb_words);
}

bool malloc_words(char **words, char *command, size_t nb_words, char *sep)
{
	size_t ic = 0;

	for (size_t i = 0; i < nb_words; i++) {
		size_t size = 0;

		for (; in(command[ic], sep); ic++);
		for (; !in(command[ic], sep) && command[ic++] != '\0'; size++);
		words[i] = malloc(sizeof(char) * (size + 1));
		if (words[i] == NULL)
			return (true);
	}
	return (false);
}

char **my_str_to_tab(char *command, char *sep)
{
	size_t nb_words = get_nb_words(command, sep);
	char **args = malloc(sizeof(char *) * (nb_words + 1));
	bool tmp = false;
	size_t j = 0;
	size_t n = 0;

	if (args && nb_words > 0 && malloc_words(args, command, nb_words, sep))
		args = NULL;
	for (size_t i = 0; args; i++) {
		in(command[i], sep) && tmp == true ? args[n][j] = '\0' : 0;
		in(command[i], sep) && tmp == true ? j = 0 : 0;
		in(command[i], sep) && tmp == true ? n++ : 0;
		in(command[i], sep) ? tmp = false : 0;
		if (command[i] == '\0')
			break;
		!in(command[i], sep) ? args[n][j++] = command[i] : 0;
		!in(command[i], sep) ? tmp = true : 0;
	}
	args ? args[nb_words] = NULL : 0;
	return (args);
}
