#ifndef TYPES
#define TYPES

#include <stdint.h>

typedef struct {
    uint8_t *red;
    uint8_t *green;
    uint8_t *blue;
    uint8_t *alpha;
} Pixel;

typedef struct {
    int rows;
    int columns;
    Pixel *pixels;
} Image;

#endif
