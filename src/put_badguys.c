/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** put_badguys.c
*/

#include "../include/rpg.h"

void put_mob(game_t *game)
{
    for (mob_t *p = game->level->range; p; p = p->next) {
        sfRenderWindow_drawSprite(game->hud->window, p->sprite, NULL);
        if (p->is_attacking) {
            boom(p, game, 2, game->hud);
        }
    }
    for (mob_t *p = game->level->melee; p; p = p->next)
        sfRenderWindow_drawSprite(game->hud->window, p->sprite, NULL);
    for (mob_t *p = game->level->b1; p; p = p->next)
        sfRenderWindow_drawSprite(game->hud->window, p->sprite, NULL);
}

void put_explosion(game_t *game)
{
    for (mob_t *p = game->level->range; p; p = p->next){
        if (p->is_attacking)
            sfRenderWindow_drawSprite(game->hud->window,
            p->kaboom->kaboom, NULL);
    }
}
