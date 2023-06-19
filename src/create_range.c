/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** create_range.c
*/

#include "../include/rpg.h"

kb_t *init_kb(void)
{
    kb_t *kab = malloc(sizeof(kb_t));

    kab->kaboom = sfSprite_create();
    kab->kaboom_t = sfTexture_createFromFile(kaboom_tex, NULL);
    sfSprite_setTexture(kab->kaboom, kab->kaboom_t, sfTrue);
    sfSprite_setTextureRect(kab->kaboom, (sfIntRect){0, 0, 128, 128});
    sfSprite_setOrigin(kab->kaboom, (sfVector2f){64, 100});
    sfSprite_setScale(kab->kaboom, (sfVector2f){0.7, 0.7});
    kab->kb_clock = sfClock_create();
    kab->cooldown_clock = sfClock_create();
    kab->kb_index = -1;
    return kab;
}

void init_range(mob_t *range)
{
    sfVector2f pos;

    memset(range, 0, sizeof(mob_t));
    range->hitbox = malloc(sizeof(hitbox_t));
    memset(range->hitbox, 0, sizeof(hitbox_t));
    range->sprite = sfSprite_create();
    range->texture = sfTexture_createFromFile(range_path, NULL);
    sfSprite_setTexture(range->sprite, range->texture, sfTrue);
    pos = get_random_postion();
    range->hitbox->size_rect = (sfIntRect){0, 0, 18, 40};
    range->origin = (sfVector2f){19, 120};
    range->hitbox_posi = (sfVector2f){12, 40};
    sfSprite_setOrigin(range->sprite, range->origin);
    sfSprite_setPosition(range->sprite, pos);
    sfSprite_setTextureRect(range->sprite, (sfIntRect){0, 0, 160, 131});
    range->hitbox->source = range;
    range->ani_clock = sfClock_create();
    range->life = 1;
    range->kaboom = init_kb();
}

void create_range(level_t *level, int nb_range)
{
    mob_t *new_range = NULL;
    mob_t *prev_range = NULL;
    hitbox_t *prev = get_last_hitbox(level->hitbox);

    for (int i = 0; i < nb_range; i++) {
        if (!new_range) {
            new_range = malloc(sizeof(mob_t));
            init_range(new_range);
            level->range = new_range;
        } else {
            new_range->next = malloc(sizeof(mob_t));
            init_range(new_range->next);
            prev = new_range->hitbox;
            prev_range = new_range;
            new_range = new_range->next;
            new_range->prev = prev_range;
        }
        new_range->hitbox->previous = prev;
        prev->next = new_range->hitbox;
    }
}
