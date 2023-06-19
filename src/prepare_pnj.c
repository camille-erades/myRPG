/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** prepare_pnj.c
*/

#include "../include/rpg.h"

pnj_t *init_pnj_text(pnj_t *pnj)
{
    pnj->pnj_speech = sfFont_createFromFile("assets/pnj_font.ttf");
    pnj->ani_clock = sfClock_create();
    pnj->fool = sfText_create();
    sfText_setFont(pnj->fool, pnj->pnj_speech);
    sfText_setCharacterSize(pnj->fool, 13);
    sfText_setString(pnj->fool, fool_man);
    pnj->item2 = sfText_create();
    sfText_setFont(pnj->item2, pnj->pnj_speech);
    sfText_setCharacterSize(pnj->item2, 13);
    sfText_setString(pnj->item2, "Choose.\n[1 = item] [2 = save]");
    pnj->first_talk = sfText_create();
    sfText_setFont(pnj->first_talk, pnj->pnj_speech);
    sfText_setCharacterSize(pnj->first_talk, 13);
    sfText_setString(pnj->first_talk, greetings);
    pnj->ground_tuto = sfText_create();
    sfText_setFont(pnj->ground_tuto, pnj->pnj_speech);
    sfText_setCharacterSize(pnj->ground_tuto, 13);
    sfText_setString(pnj->ground_tuto, tuto);
    return pnj;
}

pnj_t *init_pnj(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    pnj->pnj_sprite = sfSprite_create();
    pnj->pnj_texture = sfTexture_createFromFile(pnj_tex, NULL);
    sfSprite_setTexture(pnj->pnj_sprite, pnj->pnj_texture, sfTrue);
    sfSprite_setTextureRect(pnj->pnj_sprite, (sfIntRect){0, 0, 64, 64});
    sfSprite_setPosition(pnj->pnj_sprite, (sfVector2f){800, 800});
    return pnj;
}

level_t *init_level(void)
{
    level_t *level = malloc(sizeof(level_t));
    srand(time(NULL));
    memset(level, 0, sizeof(level_t));
    level->map = sfSprite_create();
    level->tmap = sfTexture_createFromFile(start, NULL);
    level->tmap1 = sfTexture_createFromFile(map1, NULL);
    level->tmap2 = sfTexture_createFromFile(boss1, NULL);
    level->tmap3 = sfTexture_createFromFile(boss2, NULL);
    sfSprite_setTexture(level->map, level->tmap, sfTrue);
    sfSprite_setPosition(level->map, (sfVector2f){0, 0});
    level->hitbox = init_map_hitbox(hitbox_start);
    level->pnj = init_pnj();
    level->pnj = init_pnj_text(level->pnj);
    return level;
}

inventory_t *init_items(void)
{
    inventory_t *items = malloc(sizeof(inventory_t));

    items->buf_atk_player = sfSprite_create();
    items->shield_v = sfSprite_create();
    items->the_world = sfSprite_create();
    items->buf_atk_t = sfTexture_createFromFile(buf_atk_texture, NULL);
    items->shield_v_t = sfTexture_createFromFile(shield_visu, NULL);
    items->the_world_t = sfTexture_createFromFile(the_world_tex, NULL);
    sfSprite_setTexture(items->buf_atk_player, items->buf_atk_t, sfTrue);
    sfSprite_setTextureRect(items->buf_atk_player, (sfIntRect){0, 0, 273, 155});
    sfSprite_setTexture(items->the_world, items->the_world_t, sfTrue);
    sfSprite_setTextureRect(items->the_world, (sfIntRect){0, 0, 480, 480});
    sfSprite_setTexture(items->shield_v, items->shield_v_t, sfTrue);
    sfSprite_setScale(items->the_world, (sfVector2f){0.6, 0.6});
    sfSprite_setOrigin(items->shield_v, (sfVector2f){155.5, 800});
    sfSprite_setScale(items->shield_v, (sfVector2f){0.05, 0.05});
    return items;
}
