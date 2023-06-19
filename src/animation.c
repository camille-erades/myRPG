/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** animation.c
*/

#include "../include/rpg.h"

void animate_hero(animation_t *ani, game_t *game, int type, screen_t *hud)
{
    ani->herotoview_posi = sfView_getCenter(hud->view);
    type_dash(ani, game, type, hud);
    type_idle(ani, game, type, hud);
    type_run(ani, game, type, hud);
    type_atk(ani, game, type, hud);
    type_buff_atk(ani, game, type, hud);
    the_world(ani, game, type, hud);
}

void animate_m(mob_t *m, game_t *game, int type, screen_t *hud)
{
    type_atk_m(m, game, type, hud);
    type_idle_m(m, game, type, hud);
    type_run_m(m, game, type, hud);
}

void animate_r(mob_t *r, game_t *game, int type, screen_t *hud)
{
    if (type == 1) {
        type_run_r(r, game, type, hud);
        return;
    }
    r->kaboom->kb_cooldown = sfClock_getElapsedTime(r->kaboom->cooldown_clock);
    if (sfTime_asSeconds(r->kaboom->kb_cooldown) < 2.6){
        type_idle_r(r, game, 0, hud);
    } else {
        type_atk_r(r, game, type, hud);
    }
}

void use_the_world(animation_t *ani, game_t *game)
{
    static int only_try = 0;
    if (game->player->pv < 2){
        if (only_try == 0){
            sfMusic_play(game->music->the_world);
            ani->the_worlding = sfTrue;
            only_try = 1;
        }
        if (ani->the_worlding == sfTrue){
            animate_hero(ani, game, 5, game->hud);
        }
        if (ani->items->world_ani_index >= 14){
            ani->the_worlding = sfFalse;
        }
    } else {
        sfClock_restart(ani->world_clock);
    }
}

void animation(animation_t *ani, game_t *game)
{
    if (game->player->pos_items == 3 && sfKeyboard_isKeyPressed(sfKeyG)){
        animate_hero(ani, game, 4, game->hud);
    }
    if (game->player->pos_items >= 2) {
        use_the_world(ani, game);
    }
    ani->time_stopped = sfClock_getElapsedTime(ani->world_clock);
    dash(ani, game);
    left(ani, game);
    right(ani, game);
    move_up(ani, game);
    down(ani, game);
    atk(game->hud, ani, game);
    put_pnj(ani, game, (sfVector2f){800, 800});
    animate_hero(ani, game, 0, game->hud);
}
