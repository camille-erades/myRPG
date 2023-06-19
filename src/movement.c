/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** movement.C
*/

#include "../include/rpg.h"

void move_up(animation_t *ani, game_t *game)
{
    sfVector2f direction = {ani->x, ani->y - 2};

    if (sfKeyboard_isKeyPressed(sfKeyZ)){
        type_run(ani, game, 1, game->hud);
        direction = can_move(direction, game->level->hitbox,
            game->player->hitbox, sfFalse);
        sfSprite_move(game->player->player, direction);
        sfView_move(game->hud->view, direction);
        game->player->dashdir.x = 0.0;
        game->player->dashdir.y = -2;
    }
}

void down(animation_t *ani, game_t *game)
{
    sfVector2f direction = {ani->x, ani->y + 2};

    if (sfKeyboard_isKeyPressed(sfKeyS)){
        type_run(ani, game, 1, game->hud);
        direction = can_move(direction, game->level->hitbox,
            game->player->hitbox, sfFalse);
        sfSprite_move(game->player->player, direction);
        sfView_move(game->hud->view, direction);
        game->player->dashdir.x = 0.0;
        game->player->dashdir.y = 2;
    }
}

void left(animation_t *ani, game_t *game)
{
    sfVector2f direction = {ani->x - 2, ani->y};

    if (sfKeyboard_isKeyPressed(sfKeyQ)){
        type_run(ani, game, 1, game->hud);
        sfSprite_setScale(game->player->player, (sfVector2f){-ani->hero_dir.x,
        ani->hero_dir.y});
        sfSprite_setScale(game->player->animation->items->buf_atk_player,
            (sfVector2f){ani->hero_dir.x,ani->hero_dir.y});
        direction = can_move(direction, game->level->hitbox,
            game->player->hitbox, sfFalse);
        sfSprite_move(game->player->player, direction);
        sfView_move(game->hud->view, direction);
        game->player->dashdir.x = -2.0;
        game->player->dashdir.y = 0.0;
    }
}

void right(animation_t *ani, game_t *game)
{
    sfVector2f direction = {ani->x + 2, ani->y};

    if (sfKeyboard_isKeyPressed(sfKeyD)){
        type_run(ani, game, 1, game->hud);
        sfSprite_setScale(game->player->player, (sfVector2f){ani->hero_dir.x,
        ani->hero_dir.y});
        sfSprite_setScale(game->player->animation->items->buf_atk_player,
            (sfVector2f){-ani->hero_dir.x, ani->hero_dir.y});
        direction = can_move(direction, game->level->hitbox,
            game->player->hitbox, sfFalse);
        sfSprite_move(game->player->player, direction);
        sfView_move(game->hud->view, direction);
        game->player->dashdir.x = 2.0;
        game->player->dashdir.y = 0.0;
    }
}

void dash(animation_t *ani, game_t *game)
{
    static bool is_dashing = false;
    static sfVector2f dir;

    if (sfKeyboard_isKeyPressed(sfKeyLShift) &&
        !is_dashing && sfTime_asSeconds(ani->roll_cd) > 3.0){
        is_dashing = true;
        dir = game->player->dashdir;
    }
    if (is_dashing) {
        type_dash(ani, game, 3, game->hud);
        dir = can_move(dir, game->level->hitbox,
            game->player->hitbox, sfTrue);
        sfSprite_move(game->player->player, dir);
        sfView_move(game->hud->view, dir);
        if (ani->roll_ani_index == 12){
            sfClock_restart(ani->roll_clock);
            ani->roll_ani_index = 0;
            is_dashing = false;
        }
    }
}
