/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include "rpg.h"

    typedef struct inventory_s {
        sfSprite* buf_atk_player;
        sfSprite* shield;
        sfSprite* shield_v;
        sfSprite* the_world;
        sfTexture* buf_atk_t;
        sfTexture* shield_t;
        sfTexture* shield_v_t;
        sfTexture* the_world_t;
        int buf_ani_index;
        int world_ani_index;
        int shield_ani_index;
    } inventory_t;

    typedef struct animation_s {
        sfTexture* tplayer;
        int ani_index;
        int roll_ani_index;
        sfTime ani_time;
        sfClock *ani_clock;
        sfTime roll_cd;
        sfClock *roll_clock;
        sfTime time_stopped;
        sfClock *world_clock;
        sfVector2f herotoview_posi;
        sfVector2f hero_dir;
        int x;
        int y;
        inventory_t *items;
        sfBool the_worlding;
    } animation_t;

    typedef struct player_s {
        sfSprite* player;
        sfVector2f dashdir;
        animation_t *animation;
        struct hitbox_s *hitbox;
        int pv;
        int pos_items;
    } player_t;
#endif /* !PLAYER_H_ */
