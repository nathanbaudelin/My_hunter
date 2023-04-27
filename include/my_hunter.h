/*
** EPITECH PROJECT, 2022
** bs_myhunter
** File description:
** my_hunter
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

#ifndef MY_HUNTER_H_
    #define MY_HUNTER_H_

    typedef struct my_all_sprites {
        sfClock *clock1;
        sfClock *clock2;
        sfTexture *text_my_background;
        sfTexture *text_my_target;
        sfTexture *text_my_bird;
        sfTexture *text_my_start;
        sfTexture *text_my_quit;
        sfTexture *text_my_live;
        sfTexture *text_my_restart;
        sfSprite *my_background;
        sfSprite *my_target;
        sfSprite *my_bird;
        sfSprite *my_start;
        sfSprite *my_quit;
        sfSprite *my_live1;
        sfSprite *my_live2;
        sfSprite *my_live3;
        sfSprite *my_restart;
        int score;
        int lives;
        int stop;
        float time_max;
    } my_all_sprites_t;

    void create_cible (sfSprite *sprite_cible, sfTexture *text_cible);
    void create_back (sfSprite *sprite_back, sfTexture *text_back);
    my_all_sprites_t *create_my_sprites (sfIntRect rect);
    void create_start (sfSprite *sprite_start, sfTexture *text_start);
    void create_texture (my_all_sprites_t *sprites);
    void destroy_my_sprites (my_all_sprites_t *sprite);
    void create_all_lives (my_all_sprites_t *sprites);
    void create_live (sfSprite *sprite_live, sfTexture *text_live);
    void create_all_sprites (my_all_sprites_t *sprites, sfIntRect rect);
    void create_rest (my_all_sprites_t *sprites);

    void description (void);

    void close_window (sfRenderWindow *window);
    int manage_key_pressed (sfRenderWindow *window, sfKeyEvent event,
                            my_all_sprites_t *sprites);
    int analyse_events (sfRenderWindow *window, sfEvent event, sfVector2f pos,
                        my_all_sprites_t *sprites);

    int manage_mouse_click (sfMouseButtonEvent event, sfVector2f pos,
                            my_all_sprites_t *sprites);
    void manage_mouse_moved (sfMouseMoveEvent event, sfSprite *sprite_cible);
    void dead_bird (sfVector2f *pos, my_all_sprites_t *sprites);
    int manage_mouse_click_start (sfMouseButtonEvent event,
                                    sfVector2f pos_start);
    int manage_mouse_click_leave (sfMouseButtonEvent event, sfVector2f pos_quit,
                                    my_all_sprites_t *sprites);

    void open_window (void);
    void display_window (sfRenderWindow *window, my_all_sprites_t *sprites);
    sfIntRect create_rect (int top, int left, int width, int height);
    void my_hunter(sfRenderWindow *window, sfEvent event,
                    sfIntRect *rect, my_all_sprites_t *sprite);

    void anime_clock (sfClock *clock, sfIntRect *rect, sfSprite *sprite);
    void move_clock (sfClock *clock2, my_all_sprites_t *sprites,
                            sfVector2f *pos);
    void move_bird (sfVector2f *pos, my_all_sprites_t *sprites);
    void move_rect (sfIntRect *rect, int offset, int max_value);

    int menu (sfRenderWindow *window, sfEvent event, my_all_sprites_t *sprites);
    int analyse_events_menu (sfRenderWindow *window, sfEvent event,
                            my_all_sprites_t *sprites, sfVector2f pos_start);
    int analyse_events_menu_2 (sfRenderWindow *window, sfEvent event,
                            my_all_sprites_t *sprites, sfVector2f pos_start);

    int final_screen (sfRenderWindow *window, sfEvent event,
                        my_all_sprites_t *sprites);
    int analyse_events_final (sfRenderWindow *window, sfEvent event,
                            my_all_sprites_t *sprites, sfVector2f pos_leave);
    int analyse_events_final_2 (sfRenderWindow *window, sfEvent event,
                            my_all_sprites_t *sprites, sfVector2f pos_leave);
    char *convert_int_to_str (int nb);
    void display_window_final(sfRenderWindow *window, my_all_sprites_t *sprites,
                                sfText *score);
    void create_text (sfText *score, sfFont *my_police,
                        my_all_sprites_t *sprites);

#endif /* !MY_HUNTER_H_ */
