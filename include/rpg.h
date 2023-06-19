/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #include "hitbox.h"
    #include "player.h"
    #include "entities.h"
    #include "button.h"

    #include "stdlib.h"
    #include "time.h"
    #include "unistd.h"
    #include <stdbool.h>
    #include <stdio.h>
    #include <math.h>
    #include "string.h"
    #include <fcntl.h>

    #define hero_texture "assets/entity/all_hero_mv.png"
    #define buf_atk_texture "assets/effects/buf_atk_visu.png"
    #define start "assets/map/start.png"
    #define map1 "assets/map/map1.png"
    #define boss1 "assets/map/end.png"
    #define boss2 "assets/map/end2.png"
    #define pnj_tex "assets/entity/pnj.png"
    #define shield_tex "assets/effects/shield_break.png"
    #define shield_visu "assets/effects/shield.png"
    #define the_world_tex "assets/effects/the_world.png"
    #define kaboom_tex "assets/effects/explosion-4.png"

    typedef struct level_s {
        sfTexture* tmap;
        sfTexture* tmap1;
        sfTexture* tmap2;
        sfTexture* tmap3;
        sfSprite* map;
        int nb_melee;
        int nb_range;
        mob_t *melee;
        mob_t *range;
        mob_t *b1;
        hitbox_t *hitbox;
        pnj_t *pnj;
        int lvl;
    } level_t;

    typedef struct option_s {
        int global_volum;
        int music_volume;
        sfBool full_screen;
    } option_t;

    typedef struct screen_s {
        sfRenderWindow *window;
        sfVideoMode mode;
        sfView *view;
        sfEvent event;
    } screen_t;

    typedef struct music_s {
        sfMusic *menum;
        sfMusic *battle;
        sfMusic *bossm;
        sfMusic *endm;
        sfMusic *the_world;
    } music_t;

    typedef struct game_s {
        sfBool option;
        screen_t *hud;
        player_t *player;
        level_t *level;
        menu_t *menu;
        music_t *music;
        settings_t *set;
    } game_t;

    hitbox_t *get_last_hitbox(hitbox_t *hitbox);
    sfVector2f can_move(sfVector2f direction, hitbox_t *hitbox,
        hitbox_t *currentn, sfBool dash);
    void destroy_tab(char **tab);
    int get_nbr(char const *str);
    char **my_str_to_word_array(char *str, char separator);
    hitbox_t *init_map_hitbox(char *path);
    void create_range(level_t *level, int nb_range);
    void create_melee(level_t *level, int nb_melee);
    void type_dash(animation_t *ani, game_t *game, int type, screen_t *hud);
    void type_idle(animation_t *ani, game_t *game, int type, screen_t *hud);
    void type_run(animation_t *ani, game_t *game, int type, screen_t *hud);
    void type_atk(animation_t *ani, game_t *game, int type, screen_t *hud);
    void dash(animation_t *ani, game_t *game);
    void right(animation_t *ani, game_t *game);
    void left(animation_t *ani, game_t *game);
    void down(animation_t *ani, game_t *game);
    void move_up(animation_t *ani, game_t *game);
    game_t *prepare_all(void);
    void screen(game_t *game);
    void animate_hero(animation_t *ani, game_t *game, int type, screen_t *hud);
    void destroy_all(game_t *game);
    int event_handling(animation_t *ani, game_t *game, level_t *level);
    void animation(animation_t *ani, game_t *game);
    void ani_mob_m(game_t *game);
    void animate_m(mob_t *m, game_t *game, int type, screen_t *hud);
    void type_idle_m(mob_t *m, game_t *game, int type, screen_t *hud);
    void type_atk_m(mob_t *m, game_t *game, int type, screen_t *hud);
    void type_run_m(mob_t *m, game_t *game, int type, screen_t *hud);
    void animate_r(mob_t *r, game_t *game, int type, screen_t *hud);
    void type_atk_r(mob_t *r, game_t *game, int type, screen_t *hud);
    void type_idle_r(mob_t *r, game_t *game, int type, screen_t *hud);
    void type_run_r(mob_t *r, game_t *game, int type, screen_t *hud);
    void add_hitbox(level_t *level, void *pointer);
    int test_hitbox(level_t *level, hitbox_t *hitbox, int x, int y);
    void type_buff_atk(animation_t *ani, game_t *game, int type, screen_t *hud);
    void type_idle_next(animation_t *ani, game_t *game, int type,screen_t *hud);
    void enemy_move_m(game_t *game, mob_t *enemy,  int range);
    void enemy_move_r(game_t *game, mob_t *enemy,  int range);
    void put_pnj(animation_t *ani, game_t *game, sfVector2f posi);
    void the_world(animation_t *ani, game_t *game, int type, screen_t *hud);
    void shield(animation_t *ani, game_t *game, int type, screen_t *hud);
    void actualise_mob(mob_t *mob, level_t *level);
    void destroy_mob(mob_t *mob);
    bool in_range(sfVector2f enemy, sfVector2f player, int range_x,
        int range_y);
    void attack_enemy(player_t *player, hitbox_t *list);
    void boom(mob_t *r, game_t *game, int type, screen_t *hud);
    sfBool lvl_zero(game_t *game, sfBool is_speaking);
    int lvl_one(game_t *game, sfBool is_speaking, int stage);
    void pnj_interaction(game_t *game);
    void put_explosion(game_t *game);
    void put_mob(game_t *game);
    void draw_level(game_t *game);
    void desplay_game(game_t *game);
    void game_worker(game_t *game);
    sfVector2f get_random_postion(void);
    void attack(mob_t *melee, player_t *player);
    void attack_range(mob_t *mob, hitbox_t *list);
    char **get_file(char *path);

    menu_t *init_menu(void);
    void manage_menu(boutt_t **list, sfEvent event, game_t *game);
    void lunch_game(game_t *game);
    void save_game(char *filename, int item, int level);
    void setting(game_t *game);
    void exit_game(game_t *game);
    void play_or_save(game_t *game);
    boutt_t **create_button(void);
    void destroy_hitbox(hitbox_t *hitbox);
    inventory_t *init_items(void);
    level_t *init_level(void);
    void destroy_wall(level_t *level);
    void destroy_list(mob_t *mob);
    void kill_mob(mob_t *mob, level_t *level);
    void animate_b1(mob_t *b1, game_t *game, int type, screen_t *hud);
    void enemy_move_b1(game_t *game, mob_t *b1, int range);
    void type_idle_b1(mob_t *b1, game_t *game, int type, screen_t *hud);
    void type_run_b1(mob_t *b1, game_t *game, int type, screen_t *hud);
    void type_atk_b1(mob_t *b1, game_t *game, int type, screen_t *hud);
    void create_fboss(level_t *level, int nb_melee);
    sfBool atk(screen_t *hud, animation_t *ani, game_t *game);
    void got_shield(game_t *game);
    void attack_buff(hitbox_t *list, player_t *player);
#endif /* !RPG_H_ */
