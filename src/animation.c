/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** animation
*/
#include "../include/my_hunter.h"

void display_window (sfRenderWindow *window, my_all_sprites_t *sprites)
{
    sfColor my_color = sfColor_fromRGB (147, 253, 227);
    sfRenderWindow_clear(window, my_color);
    sfRenderWindow_drawSprite(window, sprites->my_bird, NULL);
    sfRenderWindow_drawSprite(window, sprites->my_background, NULL);
    sfRenderWindow_drawSprite(window, sprites->my_target, NULL);
    if (sprites->lives >= 1)
        sfRenderWindow_drawSprite(window, sprites->my_live1, NULL);
    if (sprites->lives >= 2)
        sfRenderWindow_drawSprite(window, sprites->my_live2, NULL);
    if (sprites->lives >= 3)
        sfRenderWindow_drawSprite(window, sprites->my_live3, NULL);
    sfRenderWindow_display(window);
}

sfIntRect create_rect (int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

void my_hunter(sfRenderWindow *window, sfEvent event,
                sfIntRect *rect, my_all_sprites_t *sprites)
{
    sfVector2f pos = {0, 600};
    sfSprite_setPosition (sprites->my_bird, pos);
    if (menu (window, event, sprites) == -1)
            return;
    while (sfRenderWindow_isOpen(window) == sfTrue) {
        int ev = analyse_events (window, event, pos, sprites);
        if (ev == -1 || ev == -2)
            break;
        if (ev == 1)
            dead_bird (&pos, sprites);
        if (sprites->lives <= 0)
            break;
        anime_clock (sprites->clock1, rect, sprites->my_bird);
        move_clock (sprites->clock2, sprites, &pos);
        display_window (window, sprites);
    }
    if (sprites->stop != -1)
        final_screen (window, event, sprites);
}

void open_window (void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {800, 600, 32};
    sfEvent event;
    sfIntRect rect = create_rect (0, 0, 110, 110);
    my_all_sprites_t *sprites = create_my_sprites (rect);
    window = sfRenderWindow_create(mode, "My Window", sfDefaultStyle, NULL);
    sfRenderWindow_setMouseCursorVisible (window, sfFalse);
    sfRenderWindow_setFramerateLimit (window, 120);
    while (sprites->stop != -1) {
        my_hunter (window, event, &rect, sprites);
        sprites->lives = 3;
        sprites->score = 0;
        sprites->time_max = 0.020;
    }
    sfRenderWindow_destroy(window);
    destroy_my_sprites (sprites);
    return;
}
