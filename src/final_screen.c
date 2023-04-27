/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-nathan.baudelin
** File description:
** final_screen
*/
#include "../include/my_hunter.h"

char *convert_int_to_str (int nb)
{
    int taille = my_nbrlen (nb);
    char *str = malloc (sizeof (char) * (taille + 9));
    int i = 0;
    int d = 1;
    char *score = "Score : ";
    while (i < 8) {
        str[i] = score[i];
        i = i + 1;
    }
    while ((nb / d) >= 10)
        d = d * 10;
    while (i < (8 + taille)) {
        str[i] = (nb / d) % 10 + '0';
        i = i + 1;
        d = d / 10;
    }
    str[i] = '\0';
    return (str);
}

int analyse_events_final (sfRenderWindow *window, sfEvent event,
                        my_all_sprites_t *sprites, sfVector2f pos_leave)
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
        int res = analyse_events_final_2 (window, event, sprites, pos_leave);
        return res;
    }
    return 0;
}

void create_text (sfText *score, sfFont *my_police, my_all_sprites_t *sprites)
{
    sfColor score_color = sfColor_fromRGB (36, 55, 197);
    sfVector2f score_pos = {250, 200};
    char *str = convert_int_to_str (sprites->score);
    sfText_setString (score, str);
    sfText_setFont (score, my_police);
    sfText_setColor (score, score_color);
    sfText_setPosition (score, score_pos);
    sfText_setCharacterSize (score, 40);
    free (str);
}

void display_window_final(sfRenderWindow *window, my_all_sprites_t *sprites,
                            sfText *score)
{
    sfColor my_color = sfColor_fromRGB (147, 253, 227);
    sfRenderWindow_clear(window, my_color);
    sfRenderWindow_drawSprite(window, sprites->my_background, NULL);
    sfRenderWindow_drawText(window, score, NULL);
    sfRenderWindow_drawSprite(window, sprites->my_quit, NULL);
    sfRenderWindow_drawSprite(window, sprites->my_restart, NULL);
    sfRenderWindow_drawSprite(window, sprites->my_target, NULL);
    sfRenderWindow_display(window);
}

int final_screen (sfRenderWindow *window, sfEvent event,
                    my_all_sprites_t *sprites)
{
    sfFont *my_police = sfFont_createFromFile ("police.TTF");
    sfText *score = sfText_create();
    create_text (score, my_police, sprites);
    sfVector2f pos_quit = {300, 300};
    sfSprite_setPosition (sprites->my_quit, pos_quit);
    sfVector2f pos_restart = {255, 400};
    sfSprite_setPosition (sprites->my_restart, pos_restart);
    while (1) {
        int ev = analyse_events_final (window, event, sprites, pos_quit);
        if (ev == -1)
            break;
        display_window_final (window, sprites, score);
    }
    sfText_destroy (score);
    sfFont_destroy (my_police);
    return 0;
}
