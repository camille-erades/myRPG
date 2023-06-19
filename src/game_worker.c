/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** game_worker.c
*/

#include "../include/rpg.h"

void update_level(game_t *game)
{
    static sfBool have_changed = sfFalse;
    hitbox_t *p;

    if (have_changed)
        return;
    if (sfIntRect_contains(&game->player->hitbox->size_rect, 1016, 754)){
        sfTexture_swap(game->level->tmap, game->level->tmap1);
        game->level->lvl = 1;
        destroy_wall(game->level);
        p = get_last_hitbox(game->level->hitbox);
        p->next = init_map_hitbox(hitbox_map1);
        create_melee(game->level, 1);
        create_range(game->level, 1);
        have_changed = sfTrue;
    }
}

void mob_worker(game_t *game)
{
    for (mob_t *p = game->level->melee; p; p = p->next) {
        enemy_move_m(game, p, 100);
        actualise_mob(p, game->level);
    }
    for (mob_t *p = game->level->range; p; p = p->next) {
        enemy_move_r(game, p, 200);
        actualise_mob(p, game->level);
    }
    for (mob_t *p = game->level->b1; p; p = p->next) {
        enemy_move_b1(game, p, 200);
        actualise_mob(p, game->level);
    }
}

void game_worker(game_t *game)
{
    update_level(game);
    if (!game->option) {
        animation(game->player->animation, game);
        if (game->player->animation->the_worlding == sfFalse){
            mob_worker(game);
        }
    }
}
