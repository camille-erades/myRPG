/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** prepare_all.c
*/

#include "../include/rpg.h"

screen_t *init_hud(void)
{
    screen_t *hud = malloc(sizeof(screen_t));

    hud->mode = (sfVideoMode){1920, 1080, 32};
    hud->window = sfRenderWindow_create(hud->mode, "my_rpg",
    sfResize | sfClose, NULL);
    hud->view = sfView_create();
    sfRenderWindow_setFramerateLimit(hud->window, 60);
    sfView_setSize(hud->view, (sfVector2f){500, 300});
    sfView_setCenter(hud->view, (sfVector2f){680, 750});
    return hud;
}

animation_t *init_animation(player_t *player)
{
    animation_t* animation = malloc(sizeof(animation_t));

    memset(animation, 0, sizeof(animation_t));
    animation->tplayer = sfTexture_createFromFile(hero_texture, NULL);
    animation->hero_dir = sfSprite_getScale(player->player);
    animation->ani_clock = sfClock_create();
    animation->roll_clock = sfClock_create();
    animation->world_clock = sfClock_create();
    animation->items = init_items();
    return animation;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->player = sfSprite_create();
    player->animation = init_animation(player);
    sfSprite_setTexture(player->player, player->animation->tplayer, sfTrue);
    sfSprite_setTextureRect(player->player, (sfIntRect){0, 0, 34, 38});
    sfSprite_setOrigin(player->player, (sfVector2f){50, 19});
    player->hitbox = malloc(sizeof(hitbox_t));
    memset(player->hitbox, 0 ,sizeof(hitbox_t));
    player->hitbox->size_rect = (sfIntRect){0, 0, 17, 18};
    player->hitbox->type = PLAYER;
    player->hitbox->source = player;
    player->pv = 1;
    return player;
}

music_t *init_music(void)
{
    music_t *music = malloc(sizeof(music_t));

    music->menum = sfMusic_createFromFile("assets/music/my_rpg_menu_theme.ogg");
    music->battle = sfMusic_createFromFile("assets/music/my_rpg.ogg");
    music->bossm = sfMusic_createFromFile("assets/music/rpg_boss.ogg");
    music->endm = sfMusic_createFromFile("assets/music/my_rpg_end.ogg");
    music->the_world = sfMusic_createFromFile("assets/music/Warudo.ogg");
    return music;
}

game_t *prepare_all(void)
{
    game_t *game = malloc(sizeof(game_t));
    hitbox_t *p = NULL;

    game->option = sfTrue;
    game->level = init_level();
    game->player = init_player();
    game->hud = init_hud();
    game->menu = init_menu();
    game->music = init_music();
    game->menu->buttons = create_button();
    p = get_last_hitbox(game->level->hitbox);
    p->next = game->player->hitbox;
    game->player->hitbox->previous = p;
    return game;
}
