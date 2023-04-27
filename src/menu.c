/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-nathan.baudelin
** File description:
** menu
*/
#include "../include/my_hunter.h"

int analyse_events_menu_2 (sfRenderWindow *window, sfEvent event,
                        my_all_sprites_t *sprites, sfVector2f pos_start)
{
    if (event.type == sfEvtMouseButtonPressed) {
        int res;
        res = manage_mouse_click_start(event.mouseButton, pos_start);
        return res;
    }
    return 0;
}

int analyse_events_menu (sfRenderWindow *window, sfEvent event,
                        my_all_sprites_t *sprites, sfVector2f pos_start)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sprites->stop = -1;
            return -1;
        }
        if (event.type == sfEvtKeyPressed) {
            int stop = 0;
            stop = manage_key_pressed (window, event.key, sprites);
            return stop;
        }
        if (event.type == sfEvtMouseMoved) {
            manage_mouse_moved(event.mouseMove, sprites->my_target);
            return 0;
        }
        int res = analyse_events_menu_2 (window, event, sprites, pos_start);
        return res;
    }
    return 0;
}

int menu (sfRenderWindow *window, sfEvent event, my_all_sprites_t *sprites)
{
    sfVector2f pos_start = {260, 250};
    sfSprite_setPosition (sprites->my_start, pos_start);
    while (1) {
        int ev = analyse_events_menu (window, event, sprites, pos_start);
        if (ev == -1)
            return -1;
        if (ev == 1)
            return 1;
        sfColor my_color = sfColor_fromRGB (147, 253, 227);
        sfRenderWindow_clear(window, my_color);
        sfRenderWindow_drawSprite(window, sprites->my_background, NULL);
        sfRenderWindow_drawSprite(window, sprites->my_start, NULL);
        sfRenderWindow_drawSprite(window, sprites->my_target, NULL);
        sfRenderWindow_display(window);
    }
    return 0;
}

int analyse_events_final_2 (sfRenderWindow *window, sfEvent event,
                        my_all_sprites_t *sprites, sfVector2f pos_leave)
{
    if (event.type == sfEvtMouseButtonPressed) {
        int res;
        res = manage_mouse_click_leave(event.mouseButton, pos_leave, sprites);
        return res;
    }
    return 0;
}
