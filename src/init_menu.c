/*
** EPITECH PROJECT, 2023
** B-MUL-200-LYN-2-1-myrpg-camille.erades
** File description:
** init_menu
*/

#include "../include/rpg.h"

boutt_t *init_bouttons(sfVector2f position, sfVector2f size)
{
    boutt_t *button = malloc(sizeof(boutt_t));
    sfFloatRect spriteRect;

    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setOutlineThickness(button->rect, 1);
    spriteRect = sfRectangleShape_getGlobalBounds(button->rect);
    sfRectangleShape_setOutlineColor(button->rect, sfTransparent);
    button->bounds = (sfFloatRect){position.x, position.y ,
        spriteRect.width, spriteRect.height};
    button->state = NONE;
    return button;
}

boutt_t **create_button(void)
{
    boutt_t **list = malloc(sizeof(boutt_t *) * 4);
    char **file = get_file(butt_file);
    char **line = NULL;
    void (*function_list[])(game_t *) = {play_or_save, setting, exit_game};
    sfVector2f position;
    sfVector2f size;

    if (!file)
        return NULL;
    list[3] = NULL;
    for (int i = 0; i < 3; i++) {
        line = my_str_to_word_array(file[i], ' ');
        position = (sfVector2f){get_nbr(line[1]), get_nbr(line[2])};
        size = (sfVector2f){get_nbr(line[3]), get_nbr(line[4])};
        list[i] = init_bouttons(position, size);
        list[i]->function = function_list[i];
        destroy_tab(line);
    }
    destroy_tab(file);
    return list;
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    memset(menu, 0, sizeof(menu_t));
    menu->menu_sprite = sfSprite_create();
    menu->menu_v = sfSprite_create();
    menu->t_menu_vid = sfTexture_createFromFile(intro_t, NULL);
    menu->menu_text = sfTexture_createFromFile(menu_screen, NULL);
    menu->menu_p = sfTexture_createFromFile(m_pause, NULL);
    sfSprite_setTexture(menu->menu_v, menu->t_menu_vid, sfTrue);
    sfSprite_setTextureRect(menu->menu_v, (sfIntRect){0, 0, 840, 360});
    sfSprite_setTexture(menu->menu_sprite, menu->menu_text, sfTrue);
    sfSprite_setScale(menu->menu_sprite, (sfVector2f){0.4, 0.4});
    menu->clock_intro = sfClock_create();
    sfSprite_setOrigin(menu->menu_v, (sfVector2f){420, 180});
    sfSprite_setScale(menu->menu_v, (sfVector2f){0.9, 1});
    sfSprite_setOrigin(menu->menu_sprite, (sfVector2f){493.5, 200});
    menu->pause_i = 1;
    menu->menu_view = sfView_create();
    sfView_setSize(menu->menu_view, (sfVector2f){500, 300});
    return menu;
}

settings_t *init_settings(void)
{
    settings_t *settings = malloc(sizeof(settings_t));

    settings->s_settings = sfSprite_create();
    settings->t_settings = sfTexture_createFromFile(m_setting, NULL);
    sfSprite_setTexture(settings->s_settings, settings->t_settings, sfTrue);
    sfSprite_setOrigin(settings->s_settings, (sfVector2f){493.5, 296});
    sfSprite_setScale(settings->s_settings, (sfVector2f){0.5, 0.5});
    return settings;
}
