/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** event.c
*/

#include "../include/rpg.h"

int event_handling(animation_t *ani, game_t *game, level_t *level)
{
    sfEvent event;

    ani->roll_cd = sfClock_getElapsedTime(ani->roll_clock);
    if (level->melee)
        level->melee->ani_time =
        sfClock_getElapsedTime(level->melee->ani_clock);
    if (level->range)
        level->range->ani_time =
        sfClock_getElapsedTime(level->range->ani_clock);
    if (level->b1)
        level->b1->ani_time = sfClock_getElapsedTime(level->b1->ani_clock);
    while (sfRenderWindow_pollEvent(game->hud->window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape
            && game->menu->play_menu)
            game->option = (game->option == sfTrue) ? sfFalse : sfTrue;
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->hud->window);
        if (game->option)
            manage_menu(game->menu->buttons, event, game);
    }
}
