/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** screen.c
*/

#include "../include/rpg.h"
#include "stdio.h"

void update_view(menu_t *menu, screen_t *hud, game_t *game)
{
    sfView *view = (game->option) ? menu->menu_view : hud->view;

    sfRenderWindow_setView(hud->window, view);
}

void reset_lvl(game_t *game)
{
    if (game->player->pv <= 0) {
        if (game->level->lvl != 5) {
            kill_mob(game->level->range, game->level);
            kill_mob(game->level->melee, game->level);
            create_melee(game->level, game->level->lvl * 10);
            create_range(game->level, game->level->lvl * 10);
        } else {
            game->level->b1->life = 20;
        }
        got_shield(game);
        game->player->pv = 1;
        sfView_setCenter(game->hud->view, (sfVector2f){800, 800});
    }
}

void screen(game_t *game)
{
    sfMusic_play(game->music->menum);
    while (sfRenderWindow_isOpen(game->hud->window)) {
        reset_lvl(game);
        sfRenderWindow_clear(game->hud->window, sfBlack);
        update_view(game->menu, game->hud, game);
        event_handling(game->player->animation, game, game->level);
        game_worker(game);
        desplay_game(game);
        sfRenderWindow_setView(game->hud->window, game->hud->view);
        sfRenderWindow_display(game->hud->window);
    }
    destroy_all(game);
}
