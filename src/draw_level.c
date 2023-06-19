/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** draw_level.c
*/

#include "../include/rpg.h"

void draw_level(game_t *game)
{
    sfRenderWindow_drawSprite(game->hud->window, game->level->map, NULL);
    if (game->player->animation->items->world_ani_index < 14)
        sfRenderWindow_drawSprite(game->hud->window,
        game->player->animation->items->the_world, NULL);
    put_mob(game);
    if (sfKeyboard_isKeyPressed(sfKeyG) == sfTrue)
        sfRenderWindow_drawSprite(game->hud->window,
        game->player->animation->items->buf_atk_player, NULL);
    sfSprite_setPosition(game->player->animation->items->shield_v,
    sfSprite_getPosition(game->player->player));
    sfRenderWindow_drawSprite(game->hud->window, game->player->player, NULL);
    if (game->player->pos_items >= 1 && game->player->pv == 2)
        sfRenderWindow_drawSprite(game->hud->window,
        game->player->animation->items->shield_v, NULL);
    put_explosion(game);
}
