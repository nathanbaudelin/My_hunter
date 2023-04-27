/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-nathan.baudelin
** File description:
** my_clock
*/
#include "../include/my_hunter.h"

void anime_clock (sfClock *clock, sfIntRect *rect, sfSprite *sprite)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.20) {
        move_rect (rect, 0, 220);
        sfSprite_setTextureRect(sprite, *rect);
        sfClock_restart(clock);
    }
}

void move_clock (sfClock *clock2, my_all_sprites_t *sprites, sfVector2f *pos)
{
    sfTime time2;
    float seconds2;
    time2 = sfClock_getElapsedTime(clock2);
    seconds2 = time2.microseconds / 1000000.0;
    if (seconds2 > sprites->time_max) {
        move_bird(pos, sprites);
        sfClock_restart(clock2);
    }
}

void move_bird (sfVector2f *pos, my_all_sprites_t *sprites)
{
    if (pos->y <= -110) {
        if (pos->x > 800)
            pos->x = pos->x - 1281;
        else
            pos->x = pos->x - 381;
        pos->y = 600;
        sprites->lives = sprites->lives - 1;
    }
    pos->x = pos->x + 10;
    pos->y = pos->y - 10;
    sfSprite_setPosition (sprites->my_bird, *pos);
}

void move_rect (sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value)
        rect->left = offset;
    else
        rect->left = rect->left + 110;
}
