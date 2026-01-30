#ifndef PIXELSIM_ENTITY_H
#define PIXELSIM_ENTITY_H

#include <SDL3/SDL.h>

#include "bounds.h"

struct entity_s {
    double x;
    double y;
    double w;
    double h;
    double vel_x;
    double vel_y;
    SDL_Color color;
    bool on_ground;
};

struct entity_s* entity_new(double x, double y, double w, double h, double vel_x, double vel_y, SDL_Color color);

void entity_update(struct entity_s* entity, struct bounds_s* bounds);

void entity_render(struct entity_s* entity, SDL_Renderer* renderer);


#endif //PIXELSIM_ENTITY_H
