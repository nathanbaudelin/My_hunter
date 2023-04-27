/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-nathan.baudelin
** File description:
** sprite_2
*/

#include "../include/my_hunter.h"

void create_texture (my_all_sprites_t *sprites)
{
    sfTexture *text_back = sfTexture_createFromFile ("image/back.png", NULL);
    sfTexture *text_cible = sfTexture_createFromFile ("image/viseur.png", NULL);
    sfTexture *text_bird = sfTexture_createFromFile ("image/bird.png", NULL);
    sfTexture *text_start = sfTexture_createFromFile ("image/start.png", NULL);
    sfTexture *text_live = sfTexture_createFromFile ("image/coeur.png", NULL);
    sfTexture *text_quit = sfTexture_createFromFile ("image/quit.png", NULL);
    sfTexture *text_re = sfTexture_createFromFile ("image/restart.png", NULL);
    sprites->text_my_background = text_back;
    sprites->text_my_target = text_cible;
    sprites->text_my_bird = text_bird;
    sprites->text_my_start = text_start;
    sprites->text_my_live = text_live;
    sprites->text_my_quit = text_quit;
    sprites->text_my_restart = text_re;
}

void create_live (sfSprite *sprite_live, sfTexture *text_live)
{
    sfSprite_setTexture(sprite_live, text_live, sfFalse);
    sfVector2f scale_live = {0.05, 0.05};
    sfSprite_setScale (sprite_live, scale_live);
}

void create_all_lives (my_all_sprites_t *sprites)
{
    sfVector2f live1 = {0, 0};
    sfVector2f live2 = {50, 0};
    sfVector2f live3 = {100, 0};
    sfSprite *sprite_live1 = sfSprite_create();
    create_live (sprite_live1, sprites->text_my_live);
    sfSprite *sprite_live2 = sfSprite_create();
    create_live (sprite_live2, sprites->text_my_live);
    sfSprite *sprite_live3 = sfSprite_create();
    create_live (sprite_live3, sprites->text_my_live);
    sfSprite_setPosition (sprite_live1, live1);
    sfSprite_setPosition (sprite_live2, live2);
    sfSprite_setPosition (sprite_live3, live3);
    sprites->my_live1 = sprite_live1;
    sprites->my_live2 = sprite_live2;
    sprites->my_live3 = sprite_live3;
}

void create_all_sprites (my_all_sprites_t *sprites, sfIntRect rect)
{
    sfSprite *sprite_bird = sfSprite_create();
    sfSprite_setTexture(sprite_bird, sprites->text_my_bird, sfFalse);
    sfSprite_setTextureRect(sprite_bird, rect);
    sfSprite *sprite_cible = sfSprite_create();
    create_cible (sprite_cible, sprites->text_my_target);
    sfSprite *sprite_back = sfSprite_create();
    create_back (sprite_back, sprites->text_my_background);
    sfSprite *sprite_start = sfSprite_create();
    create_start (sprite_start, sprites->text_my_start);
    sprites->my_background = sprite_back;
    sprites->my_target = sprite_cible;
    sprites->my_bird = sprite_bird;
    sprites->my_start = sprite_start;
}

void create_rest (my_all_sprites_t *sprites)
{
    sprites->score = 0;
    sprites->lives = 3;
    sprites->stop = 0;
    sprites->clock1 = sfClock_create();
    sprites->clock2 = sfClock_create();
    sprites->time_max = 0.020;
}
