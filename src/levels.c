/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** levels.c
*/

#include "../include/rpg.h"

sfBool lvl_zero(game_t *game, sfBool is_speaking)
{
    if (game->level->lvl == 0){
        sfMusic_play(game->music->battle);
        sfMusic_setLoop(game->music->battle, sfTrue);
        sfText_setPosition(game->level->pnj->ground_tuto,
        (sfVector2f){700, 700});
        sfRenderWindow_drawText(game->hud->window,
        game->level->pnj->ground_tuto, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyF) &&
        in_range((sfVector2f){800, 800},
        game->player->animation->herotoview_posi, 100, 100))
            is_speaking = sfTrue;
        if (is_speaking && in_range((sfVector2f){800, 800},
        game->player->animation->herotoview_posi, 100, 100)){
            sfText_setPosition(game->level->pnj->first_talk,
            (sfVector2f){750, 860});
            sfRenderWindow_drawText(game->hud->window,
            game->level->pnj->first_talk, NULL);
        }
    }
    return is_speaking;
}

void got_shield(game_t *game)
{
    if (game->player->pos_items >= 1)
        game->player->pv = 2;
}

bool choosed_violence(game_t *game, bool player_is_respected)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum2))
        player_is_respected = false;
    return player_is_respected;
}

int player_choose_item(game_t *game, int stage)
{
    static bool player_is_respected = true;

    if (player_is_respected == true){
        if (sfKeyboard_isKeyPressed(sfKeyNum1)){
            game->player->pos_items++;
            got_shield(game);
            stage++;
            create_melee(game->level, 10 * stage);
            create_range(game->level, 10 * stage);
        }
        player_is_respected = choosed_violence;
        sfText_setPosition(game->level->pnj->item2, (sfVector2f){750, 860});
        sfRenderWindow_drawText(game->hud->window,
            game->level->pnj->item2, NULL);
    } else {
        sfText_setPosition(game->level->pnj->fool, (sfVector2f){750, 860});
        sfRenderWindow_drawText(game->hud->window,
            game->level->pnj->fool, NULL);
    }
    return stage;
}

int lvl_one(game_t *game, sfBool is_speaking, int stage)
{
    if (game->level->lvl == 1){
        if (stage == 3){
            got_shield(game);
            stage++;
        }
        if (sfKeyboard_isKeyPressed(sfKeyF) && in_range((sfVector2f){800, 800},
        game->player->animation->herotoview_posi, 100, 100) && stage <= 2){
            stage = player_choose_item(game, stage);
        }
    }
    return stage;
}
