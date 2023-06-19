/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** init_map_hitbox
*/

#include "../include/rpg.h"
#include "fcntl.h"
#include "sys/stat.h"

char **get_file(char *path)
{
    struct stat file_stat;
    char *buffer = NULL;
    char **tab = NULL;
    int fd = 0;
    int size = 0;

    fd = open(path, O_RDONLY);
    if (fd != -1) {
        stat(path, &file_stat);
        size = file_stat.st_size;
        if (size == 0)
            return NULL;
        buffer = malloc(sizeof(char) * (size + 1));
        read(fd, buffer, size);
        tab = my_str_to_word_array(buffer, '\n');
        free(buffer);
        return tab;
    }
    close(fd);
    return NULL;
}

static void init_hitbox_from_line(hitbox_t *hitbox, hitbox_t *prev, char * line)
{
    char **tab = NULL;

    if ((tab = my_str_to_word_array(line, ' ')) == NULL)
        return;
    hitbox->size_rect.left = get_nbr(tab[1]);
    hitbox->size_rect.top = get_nbr(tab[2]);
    hitbox->size_rect.width = get_nbr(tab[3]);
    hitbox->size_rect.height = get_nbr(tab[4]);
    hitbox->previous = prev;
    hitbox->next = NULL;
    hitbox->source = NULL;
    hitbox->type = ELSE;
    destroy_tab(tab);
}

hitbox_t *init_map_hitbox(char *path)
{
    char **file = NULL;
    hitbox_t *new = NULL;
    hitbox_t *first_elem = NULL;

    if ((file = get_file(path)) == NULL)
        return first_elem;
    for (int i = 0; file[i]; i++) {
        if (!new) {
            new = malloc(sizeof(hitbox_t));
            init_hitbox_from_line(new, NULL, file[i]);
            first_elem = new;
        } else {
            new->next = malloc(sizeof(hitbox_t));
            init_hitbox_from_line(new->next, new, file[i]);
            new = new->next;
        }
    }
    destroy_tab(file);
    return first_elem;
}
