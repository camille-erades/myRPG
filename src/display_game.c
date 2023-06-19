/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** display_game.c
*/

#include "../include/rpg.h"

void draw_button(boutt_t **list, screen_t *hud)
{
    sfColor color[3] = {sfTransparent, {128, 128, 128, 150}, sfRed};
    sfColor outline_color;

    color[2].a -= 100;
    for (int i = 0; list[i]; i++) {
        sfRectangleShape_setFillColor(list[i]->rect, color[list[i]->state]);
        outline_color = (list[i]->state == NONE) ? sfTransparent : sfWhite;
        sfRectangleShape_setOutlineColor(list[i]->rect, outline_color);
        sfRenderWindow_drawRectangleShape(hud->window, list[i]->rect, NULL);
    }
}

void menu_visu(game_t *game, menu_t *menu)
{
    menu->intro = sfClock_getElapsedTime(menu->clock_intro);
    sfSprite_setPosition(menu->menu_v, sfView_getCenter(menu->menu_view));
    if (sfTime_asSeconds(menu->intro) > 0.02 & menu->frame <= 198){
        menu->index_intro++;
        menu->frame++;
        if (menu->index_intro >= 15){
            menu->index_intro = 0;
            menu->intro_line++;
        }
        sfSprite_setTextureRect(game->menu->menu_v,
        (sfIntRect){menu->index_intro * 840,
        menu->intro_line * 360, 840, 360});
        sfClock_restart(menu->clock_intro);
    }
    sfRenderWindow_drawSprite(game->hud->window, menu->menu_v, NULL);
    if (menu->frame >= 143) {
        sfRenderWindow_drawSprite(game->hud->window,
        menu->menu_sprite, NULL);
        draw_button(menu->buttons, game->hud);
    }
}

void desplay_game(game_t *game)
{
    static sfBool have_changed = sfFalse;

    if (game->option) {
        sfSprite_setPosition(game->menu->menu_sprite,
        sfView_getCenter(game->menu->menu_view));
        menu_visu(game, game->menu);
    } else {
        draw_level(game);
        if (game->level->melee == NULL && game->level->range == NULL &&
        game->level->lvl < 2)
            pnj_interaction(game);
    }
}
