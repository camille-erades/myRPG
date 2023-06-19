/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** hitbox
*/

#ifndef HITBOX_H_
    #define HITBOX_H_
    #include "rpg.h"

    #define hitbox_start "config/start_hitbox.txt"
    #define hitbox_map1 "config/map1_hitbox.txt"

    enum entity_type {
        MOB,
        PLAYER,
        MINI_BOSS,
        BOSS,
        ELSE
    };

    typedef struct hitbox_s {
        void *source;
        enum entity_type type;
        sfIntRect size_rect;
        struct hitbox_s *next;
        struct hitbox_s *previous;
    } hitbox_t;

#endif /* !HITBOX_H_ */
