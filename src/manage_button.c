/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** manage_button
*/

#include "../include/rpg.h"

void manage_menu(boutt_t **list, sfEvent event, game_t *game)
{
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(game->hud->window);
    sfVector2f worldPos;

    worldPos = sfRenderWindow_mapPixelToCoords(game->hud->window,
        mousePos, game->menu->menu_view);
    for (int i = 0; list[i]; i++) {
        if (!sfFloatRect_contains(&list[i]->bounds, worldPos.x, worldPos.y)) {
            list[i]->state = NONE;
            continue;
        }
        if (event.type == sfEvtMouseButtonPressed)
            list[i]->state = PRESSED;
        else
            list[i]->state = HOVER;
        if (event.type == sfEvtMouseButtonReleased)
            list[i]->function(game);
    }
}
