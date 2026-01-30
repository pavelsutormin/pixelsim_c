#include "game.h"

#include <SDL3/SDL.h>
#include <stdlib.h>
#include "config.h"
#include "entity.h"
#include "bounds.h"

bool player_left = false;
bool player_right = false;
bool jumping = false;

struct game_s* game_new() {
    struct game_s* game = malloc(sizeof(struct game_s));
    SDL_Color player_color = PLAYER_START_COLOR;
    game->player = entity_new(PLAYER_START_X, PLAYER_START_Y, PLAYER_START_W, PLAYER_START_H, PLAYER_START_VEL_X, PLAYER_START_VEL_X, player_color);
    game->bounds = bounds_new(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    game->entities_n = 1;
    game->entities = malloc(game->entities_n * sizeof(struct entity_s*));
    game->entities[game->entities_n - 1] = game->player;
    return game;
}

void game_free(struct game_s* game) {
    free(game->player);
    free(game->bounds);
    for (int i = 0; i < game->entities_n; i++) {
        free(game->entities[i]);
    }
    free(game->entities);
}

void game_update(struct game_s* game) {
    game->player->vel_y += GRAVITY;
    if (jumping && game->player->on_ground) {
        game->player->vel_y = -PLAYER_JUMP_STRENGTH;
        game->player->on_ground = false;
    }
    if (player_left) {
        game->player->vel_x -= PLAYER_SPEED;
    }
    if (player_right) {
        game->player->vel_x += PLAYER_SPEED;
    }
    entity_update(game->player, game->bounds);
}

void game_render(struct game_s* game, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    entity_render(game->player, renderer);

    SDL_RenderPresent(renderer);
}

void game_keydown(struct game_s* game, SDL_Keycode keycode) {
    if (keycode == SDLK_W || keycode == SDLK_UP) {
        jumping = true;
    }
    if (keycode == SDLK_A || keycode == SDLK_LEFT) {
        player_left = true;
    }
    if (keycode == SDLK_D || keycode == SDLK_RIGHT) {
        player_right = true;
    }
}

void game_keyup(struct game_s* game, SDL_Keycode keycode) {
    if (keycode == SDLK_W || keycode == SDLK_UP) {
        jumping = false;
    }
    if (keycode == SDLK_A || keycode == SDLK_LEFT) {
        player_left = false;
    }
    if (keycode == SDLK_D || keycode == SDLK_RIGHT) {
        player_right = false;
    }
}