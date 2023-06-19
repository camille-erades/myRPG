/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-clement.monnoire
** File description:
** destroy_tab
*/

#include "stdlib.h"

void destroy_tab(char **tab)
{
    if (tab) {
        for (int i = 0; tab[i]; i++) {
            free(tab[i]);
            tab[i] = NULL;
        }
        free(tab);
        tab = NULL;
    }
}
