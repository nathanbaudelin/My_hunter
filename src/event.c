/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** event
*/
#include "../include/my_hunter.h"

int manage_key_pressed (sfRenderWindow *window, sfKeyEvent event,
                        my_all_sprites_t *sprites)
{
    if (event.code == sfKeyEscape) {
        sfRenderWindow_close(window);
        sprites->stop = -1;
        return -1;
    }
    if (event.code == sfKeySpace)
        return -2;
    return 0;
}

int analyse_events_2 (sfEvent event, sfVector2f pos, my_all_sprites_t *sprites)
{
    if (event.type == sfEvtMouseButtonPressed) {
        int res;
        res = manage_mouse_click(event.mouseButton, pos, sprites);
        return res;
    }
    if (event.type == sfEvtMouseMoved) {
        manage_mouse_moved(event.mouseMove, sprites->my_target);
        return 0;
    }
    return 0;
}

int analyse_events (sfRenderWindow *window, sfEvent event, sfVector2f pos,
                    my_all_sprites_t *sprites)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            sprites->stop = -1;
            return -1;
        }
        if (event.type == sfEvtKeyPressed) {
            int stop = 0;
            stop = manage_key_pressed (window, event.key, sprites);
            return stop;
        }
        int res = analyse_events_2 (event, pos, sprites);
        return (res);
    }
    return 0;
}
