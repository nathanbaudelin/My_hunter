/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-nathan.baudelin
** File description:
** mouse_events
*/
#include "../include/my_hunter.h"

void dead_bird (sfVector2f *pos, my_all_sprites_t *sprites)
{
    if (pos->x < 500)
        pos->x = pos->x - 158;
    else
        pos->x = pos->x - 753;
    pos->y = 600;
    sfSprite_setPosition (sprites->my_bird, *pos);
    sprites->time_max = sprites->time_max - 0.001;
}

int manage_mouse_click (sfMouseButtonEvent event, sfVector2f pos,
                        my_all_sprites_t *sprites)
{
    if (event.x >= pos.x && event.x <= (pos.x + 110)
    && event.y >= pos.y && event.y <= (pos.y + 110)) {
        sprites->score = sprites->score + 1;
        return 1;
    } else
        return 0;
}

void manage_mouse_moved (sfMouseMoveEvent event, sfSprite *sprite_cible)
{
    sfVector2f pos_cible = {(event.x - 25), (event.y - 25)};
    sfSprite_setPosition (sprite_cible, pos_cible);
}

int manage_mouse_click_start (sfMouseButtonEvent event, sfVector2f pos_start)
{
    if (event.x >= pos_start.x && event.x <= (pos_start.x + 255)
    && event.y >= pos_start.y && event.y <= (pos_start.y + 100))
        return 1;
    else
        return 0;
}

int manage_mouse_click_leave (sfMouseButtonEvent event, sfVector2f pos_quit,
                                my_all_sprites_t *sprites)
{
    if (event.x >= pos_quit.x && event.x <= (pos_quit.x + 200)
    && event.y >= pos_quit.y && event.y <= (pos_quit.y + 70)) {
        sprites->stop = -1;
        return -1;
    }
    if (event.x >= (pos_quit.x - 45) && event.x <= ((pos_quit.x - 45) + 275)
    && event.y >= (pos_quit.y + 100) && event.y <= ((pos_quit.y + 100) + 100))
        return -1;
    return 0;
}
