#ifndef PIXELSIM_BOUNDS_H
#define PIXELSIM_BOUNDS_H

struct bounds_s {
    double min_x;
    double min_y;
    double max_x;
    double max_y;
};

struct bounds_s* bounds_new(double min_x, double min_y, double max_x, double max_y);


#endif //PIXELSIM_BOUNDS_H
