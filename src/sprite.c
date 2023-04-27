/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-nathan.baudelin
** File description:
** sprite
*/
#include "../include/my_hunter.h"

void create_cible (sfSprite *sprite_cible, sfTexture *text_cible)
{
    sfIntRect rect_cible = create_rect (0, 0, 600, 600);
    sfSprite_setTexture(sprite_cible, text_cible, sfFalse);
    sfSprite_setTextureRect(sprite_cible, rect_cible);
    sfVector2f scale_cible = {0.1, 0.1};
    sfSprite_setScale (sprite_cible, scale_cible);
}

void create_back (sfSprite *sprite_back, sfTexture *text_back)
{
    sfIntRect rect_back = create_rect (5, 5, 1200, 800);
    sfSprite_setTexture(sprite_back, text_back, sfFalse);
    sfSprite_setTextureRect(sprite_back, rect_back);
    sfVector2f scale_back = {0.70, 0.75};
    sfSprite_setScale (sprite_back, scale_back);
}

void create_start (sfSprite *sprite_start, sfTexture *text_start)
{
    sfSprite_setTexture(sprite_start, text_start, sfFalse);
    sfVector2f scale_start = {0.4, 0.4};
    sfSprite_setScale (sprite_start, scale_start);
}

my_all_sprites_t *create_my_sprites (sfIntRect rect)
{
    my_all_sprites_t *sprites = malloc (sizeof(my_all_sprites_t));
    create_texture (sprites);
    create_all_lives (sprites);
    create_all_sprites (sprites, rect);
    sfSprite *sprite_quit = sfSprite_create();
    sfSprite_setTexture(sprite_quit, sprites->text_my_quit, sfFalse);
    sfVector2f scale_quit = {0.6, 0.6};
    sfSprite_setScale (sprite_quit, scale_quit);
    sfSprite *sprite_restart = sfSprite_create();
    sfSprite_setTexture(sprite_restart, sprites->text_my_restart, sfFalse);
    sfVector2f scale_restart = {0.6, 0.6};
    sfSprite_setScale (sprite_restart, scale_restart);
    sprites->my_quit = sprite_quit;
    sprites->my_restart = sprite_restart;
    create_rest (sprites);
    return (sprites);
}

void destroy_my_sprites (my_all_sprites_t *sprites)
{
    sfTexture_destroy (sprites->text_my_background);
    sfTexture_destroy (sprites->text_my_target);
    sfTexture_destroy (sprites->text_my_bird);
    sfTexture_destroy (sprites->text_my_start);
    sfTexture_destroy (sprites->text_my_quit);
    sfTexture_destroy (sprites->text_my_restart);
    sfSprite_destroy (sprites->my_background);
    sfSprite_destroy (sprites->my_target);
    sfSprite_destroy (sprites->my_bird);
    sfSprite_destroy (sprites->my_start);
    sfSprite_destroy (sprites->my_quit);
    sfSprite_destroy (sprites->my_restart);
    sfSprite_destroy (sprites->my_live1);
    sfSprite_destroy (sprites->my_live2);
    sfSprite_destroy (sprites->my_live3);
    sfClock_destroy (sprites->clock1);
    sfClock_destroy (sprites->clock2);
    free (sprites);
}
