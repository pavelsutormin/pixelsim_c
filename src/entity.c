#include "entity.h"

#include <SDL3/SDL.h>
#include <stdlib.h>
#include "config.h"
#include "utils.h"


struct entity_s* entity_new(double x, double y, double w, double h, double vel_x, double vel_y, SDL_Color color) {
    struct entity_s* entity = malloc(sizeof(struct entity_s));
    entity->x = x;
    entity->y = y;
    entity->w = w;
    entity->h = h;
    entity->vel_x = vel_x;
    entity->vel_y = vel_y;
    entity->color = color;
    entity->on_ground = false;
    return entity;
}

void entity_update(struct entity_s* entity, struct bounds_s* bounds) {
    entity->vel_x = closen_to_zero(entity->vel_x, FRICTION);
    entity->vel_y = closen_to_zero(entity->vel_y, FRICTION);
    entity->x += entity->vel_x;
    entity->y += entity->vel_y;

    if (entity->x < bounds->min_x) {
        entity->x = bounds->min_x;
        entity->vel_x = -entity->vel_x * BOUNCE_DAMP;
    }
    if (entity->x > bounds->max_x - entity->w) {
        entity->x = bounds->max_x - entity->w;
        entity->vel_x = -entity->vel_x * BOUNCE_DAMP;
    }
    if (entity->y < bounds->min_y) {
        entity->y = bounds->min_y;
        entity->vel_y = -entity->vel_y * BOUNCE_DAMP;
    }
    if (entity->y > bounds->max_y - entity->h) {
        entity->y = bounds->max_y - entity->h;
        entity->vel_y = -entity->vel_y * BOUNCE_DAMP;
        entity->on_ground =  true;
    }
}

void entity_render(struct entity_s* entity, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, entity->color.r, entity->color.g, entity->color.b, entity->color.a);
    SDL_FRect rect = {entity->x, entity->y, entity->w, entity->h};
    SDL_RenderFillRect(renderer, &rect);
}