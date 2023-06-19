/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** destroy_all.c
*/

#include "../include/rpg.h"

void update_wall(hitbox_t *hitbox)
{
    if (hitbox->type == ELSE) {
            if (hitbox->previous)
                hitbox->previous->next = hitbox->next;
            if (hitbox->next)
                hitbox->next->previous = hitbox->previous;
            free(hitbox);
        }
}

void destroy_wall(level_t *level)
{
    hitbox_t *current = level->hitbox;
    hitbox_t *tmp = NULL;

    while (current) {
        tmp = current->next;
        update_wall(current);
        if (!tmp)
            break;
        current = tmp;
    }
    while (current && current->previous)
        current = current->previous;
    level->hitbox = current;
}

void destroy_hitbox(hitbox_t *hitbox)
{
    hitbox_t *next = NULL;

    while (hitbox) {
        next = hitbox->next;
        free(hitbox);
        hitbox = NULL;
        hitbox = next;
    }
}

void destroy_menu(menu_t * menu)
{
    sfTexture_destroy(menu->menu_text);
    sfTexture_destroy(menu->t_menu_vid);
    sfTexture_destroy(menu->menu_p);
    sfSprite_destroy(menu->menu_v);
    sfSprite_destroy(menu->menu_sprite);
    sfClock_destroy(menu->clock_intro);
    sfView_destroy(menu->menu_view);
    for (int i = 0; menu->buttons[i]; i++) {
        sfRectangleShape_destroy(menu->buttons[i]->rect);
        free(menu->buttons[i]);
    }
    free(menu->buttons);
}

void destroy_all(game_t *game)
{
    sfRenderWindow_destroy(game->hud->window);
    sfTexture_destroy(game->level->tmap);
    sfSprite_destroy(game->level->map);
    sfSprite_destroy(game->player->player);
    sfTexture_destroy(game->player->animation->tplayer);
    sfView_destroy(game->hud->view);
    destroy_list(game->level->range);
    destroy_list(game->level->melee);
    destroy_hitbox(game->level->hitbox);
    destroy_menu(game->menu);
    free(game->hud);
    free(game->player);
    free(game->level);
}
