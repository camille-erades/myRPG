/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** create_melee.c
*/

#include "../include/rpg.h"

void init_fboss(mob_t *b1)
{
    sfVector2f pos;

    memset(b1, 0, sizeof(mob_t));
    b1->hitbox = malloc(sizeof(hitbox_t));
    memset(b1->hitbox, 0, sizeof(hitbox_t));
    b1->sprite = sfSprite_create();
    b1->texture = sfTexture_createFromFile(fboss, NULL);
    sfSprite_setTexture(b1->sprite, b1->texture, sfTrue);
    sfSprite_setTextureRect(b1->sprite, (sfIntRect){0, 0, 145, 146.25});
    pos = get_random_postion();
    b1->hitbox->size_rect = (sfIntRect){0, 0, 72.5, 73.125};
    b1->origin = (sfVector2f){72.5, 120};
    b1->hitbox_posi = (sfVector2f){30, 65};
    sfSprite_setOrigin(b1->sprite, b1->origin);
    sfSprite_setPosition(b1->sprite, pos);
    sfSprite_setScale(b1->sprite, (sfVector2f){2, 2});
    b1->hitbox->source = b1;
    b1->ani_clock = sfClock_create();
    b1->life = 20;
    sfSprite_setPosition(b1->sprite, (sfVector2f){1400, 800});
}

void create_fboss(level_t *level, int nb_melee)
{
    mob_t *new_melee = NULL;
    mob_t *prev_melee = NULL;
    hitbox_t *prev = get_last_hitbox(level->hitbox);

    for (int i = 0; i < nb_melee; i++) {
        if (!new_melee) {
            new_melee = malloc(sizeof(mob_t));
            init_fboss(new_melee);
            level->b1 = new_melee;
        } else {
            new_melee->next = malloc(sizeof(mob_t));
            init_fboss(new_melee->next);
            prev = new_melee->hitbox;
            prev_melee = new_melee;
            new_melee = new_melee->next;
            new_melee->prev = prev_melee;
        }
        new_melee->hitbox->previous = prev;
        prev->next = new_melee->hitbox;
    }
}

void init_melee(mob_t *melee)
{
    sfVector2f pos;

    memset(melee, 0, sizeof(mob_t));
    melee->hitbox = malloc(sizeof(hitbox_t));
    memset(melee->hitbox, 0, sizeof(hitbox_t));
    melee->sprite = sfSprite_create();
    melee->texture = sfTexture_createFromFile(melee_path, NULL);
    sfSprite_setTexture(melee->sprite, melee->texture, sfTrue);
    pos = get_random_postion();
    melee->hitbox->size_rect = (sfIntRect){0, 0, 22.4, 48};
    melee->origin = (sfVector2f){90, 130};
    melee->hitbox_posi = (sfVector2f){10, 35};
    sfSprite_setOrigin(melee->sprite, melee->origin);
    sfSprite_setPosition(melee->sprite, pos);
    sfSprite_setTextureRect(melee->sprite, (sfIntRect){0, 0, 250, 151});
    sfSprite_setScale(melee->sprite, (sfVector2f){0.6, 0.6});
    melee->hitbox->source = melee;
    melee->ani_clock = sfClock_create();
    melee->life = 1;
}

void create_melee(level_t *level, int nb_melee)
{
    mob_t *new_melee = NULL;
    mob_t *prev_melee = NULL;
    hitbox_t *prev = get_last_hitbox(level->hitbox);

    for (int i = 0; i < nb_melee; i++) {
        if (!new_melee) {
            new_melee = malloc(sizeof(mob_t));
            init_melee(new_melee);
            level->melee = new_melee;
        } else {
            new_melee->next = malloc(sizeof(mob_t));
            init_melee(new_melee->next);
            prev = new_melee->hitbox;
            prev_melee = new_melee;
            new_melee = new_melee->next;
            new_melee->prev = prev_melee;
        }
        new_melee->hitbox->previous = prev;
        prev->next = new_melee->hitbox;
    }
}
