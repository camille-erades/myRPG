/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** button
*/

#ifndef BUTTON_H_
    #define BUTTON_H_
    #include "rpg.h"

    #define butt_file "config/button_posi.txt"
    #define menu_screen "assets/icones/title_screen_text.png"
    #define intro_t "assets/icones/myrpg_menu_intro_sheet.png"
    #define m_pause "assets/icones/pause_screen_text.png"
    #define m_setting "assets/icones/setting_screen_text.png"

    typedef struct game_s game_t;

        enum e_gui_state {
        NONE = 0,
        HOVER,
        PRESSED
        };

    typedef struct boutt_s {
        sfRectangleShape *rect;
        sfFloatRect bounds;
        enum e_gui_state state;
        void (*function)(game_t *);
    } boutt_t;

    typedef struct settings_s {
        sfTexture *t_settings;
        sfSprite *s_settings;
    } settings_t;

    typedef struct menu_s {
        sfTexture *menu_text;
        sfTexture *menu_p;
        sfSprite *menu_sprite;
        sfSprite *menu_v;
        sfTexture *t_menu_vid;
        sfClock *clock_intro;
        sfTime intro;
        int index_intro;
        int intro_line;
        int frame;
        int pause_i;
        sfView *menu_view;
        boutt_t **buttons;
        sfBool play_menu;
    } menu_t;

#endif /* !BUTTON_H_ */
