#ifndef PIXELSIM_GAME_H
#define PIXELSIM_GAME_H

#include <SDL3/SDL.h>
#include "entity.h"
#include "bounds.h"

struct game_s {
	struct entity_s* player;
	struct bounds_s* bounds;

	int entities_n;
	struct entity_s** entities;
};

struct game_s* game_new();

void game_update(struct game_s* game);

void game_render(struct game_s* game, SDL_Renderer* renderer);

void game_keydown(struct game_s* game, SDL_Keycode keycode);

void game_keyup(struct game_s* game, SDL_Keycode keycode);

void game_add_entity(struct game_s* game, struct entity_s* entity);

#endif //PIXELSIM_GAME_H