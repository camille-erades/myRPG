/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** entities
*/

#ifndef ENTITIES_H_
    #define ENTITIES_H_
    #include "rpg.h"

    #define range_path "assets/entity/range.png"
    #define melee_path "assets/entity/melee.png"
    #define fboss "assets/entity/boss2allmoves.png"

    #define range_path "assets/entity/range.png"
    #define melee_path "assets/entity/melee.png"
    #define tuto "[Z Q S D] to move,\n[LSHIFT] to roll,\n[F] to interact,\n"\
    "[G] to attack, [num1] & [num2] to choose."
    #define greetings "You don't need my name\nand i don't need yours either."\
    "\nproove your ego\nis great enough to get out of the purgatory\nand "\
    "don't break your precepts for an easy choice.\nAs long as you do it,\n"\
    "i will provide my help."
    #define fool_man "Your actions are a disgrace to\nthe very "\
    "concept of knighthood.\nDon't expect anything more of me."

    typedef struct kb_s {
        sfSprite *kaboom;
        sfTexture *kaboom_t;
        sfTime kb_cd;
        sfClock *kb_clock;
        int kb_index;
        sfTime kb_cooldown;
        sfClock *cooldown_clock;
    } kb_t;

    typedef struct mob_s {
        sfBool is_attacking;
        sfSprite *sprite;
        sfTexture *texture;
        int life;
        struct mob_s *next;
        struct mob_s *prev;
        sfTime ani_time;
        sfClock *ani_clock;
        int ani_index;
        int atk_index;
        struct hitbox_s *hitbox;
        sfVector2f origin;
        sfVector2f hitbox_posi;
        kb_t *kaboom;
    } mob_t;

    typedef struct pnj_s {
        sfSprite *pnj_sprite;
        sfTexture *pnj_texture;
        sfText* first_talk;
        sfText* ground_tuto;
        sfText* item2;
        sfText* fool;
        sfFont* pnj_speech;
        sfTime ani_time;
        sfClock *ani_clock;
        int ani_index;
    } pnj_t;

#endif /* !ENTITIES_H_ */
