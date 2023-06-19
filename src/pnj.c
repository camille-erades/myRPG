/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** pnj.c
*/

#include "../include/rpg.h"

void pnj_interaction(game_t *game)
{
    static sfBool is_speaking = sfFalse;
    static int stage = 0;
    sfRenderWindow_drawSprite(game->hud->window, game->level->pnj->pnj_sprite,
    NULL);
    is_speaking = lvl_zero(game, is_speaking);
    stage = lvl_one(game, is_speaking, stage);
    if (stage == 4){
        sfTexture_swap(game->level->tmap, game->level->tmap2);
        create_fboss(game->level, 1);
        sfMusic_play(game->music->bossm);
        sfMusic_stop(game->music->battle);
        sfMusic_setLoop(game->music->bossm, sfTrue);
        stage++;
    }
}
