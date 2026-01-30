#include "bounds.h"

#include <stdlib.h>

struct bounds_s* bounds_new(double min_x, double min_y, double max_x, double max_y) {
    struct bounds_s* bounds = malloc(sizeof(struct bounds_s));
    bounds->min_x = min_x;
    bounds->min_y = min_y;
    bounds->max_x = max_x;
    bounds->max_y = max_y;
    return bounds;
}
