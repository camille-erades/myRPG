/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** button_function
*/

#include "../include/rpg.h"

void lunch_game(game_t *game)
{
    game->menu->pause_i = 2;
    game->option = sfFalse;
    sfSprite_setTexture(game->menu->menu_sprite, game->menu->menu_p, sfFalse);
    sfSprite_setOrigin(game->menu->menu_sprite, (sfVector2f){493.5, 296});
    sfSprite_setPosition(game->menu->menu_sprite,
        sfView_getCenter(game->menu->menu_view));
    sfSprite_setScale(game->menu->menu_sprite, (sfVector2f){0.52, 0.52});
    game->menu->play_menu = sfTrue;
}

void save_game(char *filename, int item, int level)
{
    int fd = open(filename, O_CREAT, 0666);
    FILE* file = fopen(filename, "wb");

    if (file != NULL) {
        fwrite(&item, sizeof(int), 1, file);
        fwrite(&level, sizeof(int), 1, file);
        fclose(file);
        write(1, "Game saved.\n", 13);
    } else {
        write(2, "Error: could not open file for writing the save.\n", 50);
    }
}

void setting(game_t *game)
{
    return;
}

void exit_game(game_t *game)
{
    sfRenderWindow_close(game->hud->window);
}

void play_or_save(game_t *game)
{
    static sfBool play = sfFalse;

    if (!play)
        lunch_game(game);
    else
        save_game("save.txt", game->menu->frame, game->menu->pause_i);
    play = sfTrue;
}
