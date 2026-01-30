#include "utils.h"

#include <math.h>

double closen_to_zero(double x, double y) {
    if (x > 0) {
        x -= y;
        if (x < 0) return 0;
    } 
    else if (x < 0) {
        x += y;
        if (x > 0) return 0;
    }
    return x;
}

void normalize(double* x, double* y) {
    double len = sqrt(*x**x+*y**y);

    if (len > 0) {
        *x /= len;
        *y /= len;
    }
}