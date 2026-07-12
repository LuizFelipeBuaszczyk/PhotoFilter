#include <stdio.h>
#include "types.h"

static int add_value (uint8_t value, Image *image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red + value > 255) {
            *image->pixels[i].red = 255;
        } else {
            *image->pixels[i].red += value;
        }

        if (*image->pixels[i].green + value > 255) {
            *image->pixels[i].green = 255;
        } else {
            *image->pixels[i].green += value;
        }

        if (*image->pixels[i].blue + value > 255) {
            *image->pixels[i].blue = 255;
        } else {
            *image->pixels[i].blue += value;
        }
    }
    
    return 0;
}

static int subt_value (uint8_t value, Image *image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red - value < 0) {
            *image->pixels[i].red = 0;
        } else {
            *image->pixels[i].red -= value;
        }

        if (*image->pixels[i].green - value < 0) {
            *image->pixels[i].green = 0;
        } else {
            *image->pixels[i].green -= value;
        }

        if (*image->pixels[i].blue - value < 0) {
            *image->pixels[i].blue = 0;
        } else {
            *image->pixels[i].blue -= value;
        }
    }
    
    return 0;
}

static int multiply_value (uint8_t value, Image *image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red * value > 255) {
            *image->pixels[i].red = 255;
        } else {
            *image->pixels[i].red *= value;
        }

        if (*image->pixels[i].green * value > 255) {
            *image->pixels[i].green = 255;
        } else {
            *image->pixels[i].green *= value;
        }

        if (*image->pixels[i].blue * value > 255) {
            *image->pixels[i].blue = 255;
        } else {
            *image->pixels[i].blue *= value;
        }
    }
    
    return 0;
}


static int div_value (uint8_t value, Image *image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red / value < 0) {
            *image->pixels[i].red = 0;
        } else {
            *image->pixels[i].red /= value;
        }

        if (*image->pixels[i].green / value < 0) {
            *image->pixels[i].green = 0;
        } else {
            *image->pixels[i].green /= value;
        }

        if (*image->pixels[i].blue / value < 0) {
            *image->pixels[i].blue = 0;
        } else {
            *image->pixels[i].blue /= value;
        }
    }
    
    return 0;
}

