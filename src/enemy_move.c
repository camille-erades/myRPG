/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** enemy_move.c
*/

#include "../include/rpg.h"

bool in_range(sfVector2f enemy, sfVector2f player, int range_x, int range_y)
{
    float x;
    float y;
    int result;

    x = player.x - enemy.x;
    y = player.y - enemy.y;
    if (abs(x) > range_x)
        return sfFalse;
    if (abs(y) > range_y)
        return sfFalse;
    return sfTrue;
}

void enemy_move_b1(game_t *game, mob_t *b1,  int range)
{
    sfVector2f pos, pos_player, move = {0, 0};

    pos = sfSprite_getPosition(b1->sprite);
    pos_player = sfSprite_getPosition(game->player->player);
    if (pos.x >= pos_player.x + 1.5 || pos.x <= pos_player.x - 1.5)
        move.x = (pos.x - pos_player.x > 0) ? -1.5 : +1.5;
    if (pos.y >= pos_player.y + 1.5 || pos.y <= pos_player.y - 1.5)
        move.y = (pos.y - pos_player.y > 0) ? -1.5 : +1.5;
    sfSprite_setScale(b1->sprite, (sfVector2f){((move.x < 0) ? -2 : 2), 2});
    sfSprite_setOrigin(b1->sprite, b1->origin);
    if (in_range(pos, pos_player, 90, 10)) {
        animate_b1(b1, game, 2, game->hud);
        attack(b1, game->player);
        return;
    }
    if (b1->atk_index == 0) {
        move = can_move(move, game->level->hitbox, b1->hitbox, sfFalse);
        sfSprite_move(b1->sprite, move);
    }
    animate_b1(b1, game, 1, game->hud);
}

void enemy_move_m(game_t *game, mob_t *enemy,  int range)
{
    sfVector2f pos, pos_player, move = {0, 0};

    pos = sfSprite_getPosition(enemy->sprite);
    pos_player = sfSprite_getPosition(game->player->player);
    if (pos.x >= pos_player.x + 1.5 || pos.x <= pos_player.x - 1.5)
        move.x = (pos.x - pos_player.x > 0) ? -1.5 : +1.5;
    if (pos.y >= pos_player.y + 1.5 || pos.y <= pos_player.y - 1.5)
        move.y = (pos.y - pos_player.y > 0) ? -1.5 : +1.5;
    sfSprite_setScale(enemy->sprite, (sfVector2f){((move.x < 0) ? -1 : 1), 1});
    sfSprite_setOrigin(enemy->sprite, enemy->origin);
    if (in_range(pos, pos_player, 58, 8)) {
        animate_m(enemy, game, 2, game->hud);
        return;
    }
    if (enemy->atk_index == 0) {
        move = can_move(move, game->level->hitbox, enemy->hitbox, sfFalse);
        sfSprite_move(enemy->sprite, move);
    }
    animate_m(enemy, game, 1, game->hud);
}

void enemy_move_r(game_t *game, mob_t *enemy,  int range)
{
    sfVector2f pos, pos_player, move = {0, 0};
    pos = sfSprite_getPosition(enemy->sprite);
    pos_player = sfSprite_getPosition(game->player->player);
    if (pos.x >= pos_player.x + 1.5 || pos.x <= pos_player.x - 1.5)
        move.x = (pos.x - pos_player.x > 0) ? -1.5 : +1.5;
    if (pos.y >= pos_player.y + 1.5 || pos.y <= pos_player.y - 1.5)
        move.y = (pos.y - pos_player.y > 0) ? -1.5 : +1.5;
    sfSprite_setScale(enemy->sprite, (sfVector2f){((move.x < 0) ? -1 : 1), 1});
    sfSprite_setOrigin(enemy->sprite, enemy->origin);
    if (in_range(pos, pos_player, 170, 170)) {
        animate_r(enemy, game, 2, game->hud);
        return;
    }
    move = can_move(move, game->level->hitbox, enemy->hitbox, sfFalse);
    sfSprite_move(enemy->sprite, move);
    animate_r(enemy, game, 1, game->hud);
}
