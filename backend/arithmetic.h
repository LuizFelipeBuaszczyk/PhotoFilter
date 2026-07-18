#include <stdio.h>
#include "types.h"

static int add_value (uint8_t value, Image *image, Image *result_image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red + value > 255) {
            *result_image->pixels[i].red = 255;
        } else {
            *result_image->pixels[i].red = *image->pixels[i].red + value;
        }

        if (*image->pixels[i].green + value > 255) {
            *result_image->pixels[i].green = 255;
        } else {
            *result_image->pixels[i].green = *image->pixels[i].green + value;
        }

        if (*image->pixels[i].blue + value > 255) {
            *result_image->pixels[i].blue = 255;
        } else {
            *result_image->pixels[i].blue = *image->pixels[i].blue + value;
        }

        *result_image->pixels[i].alpha = *image->pixels[i].alpha;
    }
    
    return 0;
}

static int subt_value (uint8_t value, Image *image, Image *result_image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red - value < 0) {
            *result_image->pixels[i].red = 0;
        } else {
            *result_image->pixels[i].red = *image->pixels[i].red - value;
        }

        if (*image->pixels[i].green - value < 0) {
            *result_image->pixels[i].green = 0;
        } else {
            *result_image->pixels[i].green =  *image->pixels[i].green - value;
        }

        if (*image->pixels[i].blue - value < 0) {
            *result_image->pixels[i].blue = 0;
        } else {
            *result_image->pixels[i].blue = *image->pixels[i].blue -value;
        }
        *result_image->pixels[i].alpha = *image->pixels[i].alpha;
    }
    
    return 0;
}

static int multiply_value (uint8_t value, Image *image, Image *result_image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red * value > 255) {
            *result_image->pixels[i].red = 255;
        } else {
            *result_image->pixels[i].red = *image->pixels[i].red * value;
        }

        if (*image->pixels[i].green * value > 255) {
            *result_image->pixels[i].green = 255;
        } else {
            *result_image->pixels[i].green = *image->pixels[i].green * value;
        }

        if (*image->pixels[i].blue * value > 255) {
            *result_image->pixels[i].blue = 255;
        } else {
            *result_image->pixels[i].blue = *image->pixels[i].blue * value;
        }
        *result_image->pixels[i].alpha = *image->pixels[i].alpha;
    }
    
    return 0;
}


static int div_value (uint8_t value, Image *image, Image *result_image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red / value < 0) {
            *result_image->pixels[i].red = 0;
        } else {
            *result_image->pixels[i].red = *image->pixels[i].red / value;
        }

        if (*image->pixels[i].green / value < 0) {
            *result_image->pixels[i].green = 0;
        } else {
            *result_image->pixels[i].green = *image->pixels[i].green / value;
        }

        if (*image->pixels[i].blue / value < 0) {
           *result_image->pixels[i].blue = 0;
        } else {
            *result_image->pixels[i].blue = *image->pixels[i].blue / value;
        }
        *result_image->pixels[i].alpha = *image->pixels[i].alpha;
    }
    
    return 0;
}

