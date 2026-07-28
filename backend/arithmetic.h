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

static int add_image (Image *image, Image *image_to_add, Image *result_image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red + *image_to_add->pixels[i].red > 255) {
            *result_image->pixels[i].red = 255;
        } else {
            *result_image->pixels[i].red = *image->pixels[i].red + *image_to_add->pixels[i].red;
        }

        if (*image->pixels[i].green + *image_to_add->pixels[i].green > 255) {
            *result_image->pixels[i].green = 255;
        } else {
            *result_image->pixels[i].green = *image->pixels[i].green + *image_to_add->pixels[i].green;
        }

        if (*image->pixels[i].blue + *image_to_add->pixels[i].blue > 255) {
            *result_image->pixels[i].blue = 255;
        } else {
            *result_image->pixels[i].blue = *image->pixels[i].blue + *image_to_add->pixels[i].green;
        }

        *result_image->pixels[i].alpha = *image->pixels[i].alpha;
    }
    
    return 0;
}

static int subt_image (Image *image, Image *image_to_subt, Image *result_image) {
    for (int i=0; i<image->rows * image->columns; i++){
        if (*image->pixels[i].red - *image_to_subt->pixels[i].red < 0) {
            *result_image->pixels[i].red = 0;
        } else {
            *result_image->pixels[i].red = *image->pixels[i].red - *image_to_subt->pixels[i].red;
        }

        if (*image->pixels[i].green - *image_to_subt->pixels[i].green < 0) {
            *result_image->pixels[i].green = 0;
        } else {
            *result_image->pixels[i].green = *image->pixels[i].green - *image_to_subt->pixels[i].green;
        }

        if (*image->pixels[i].blue - *image_to_subt->pixels[i].blue < 0) {
            *result_image->pixels[i].blue = 0;
        } else {
            *result_image->pixels[i].blue = *image->pixels[i].blue - *image_to_subt->pixels[i].green;
        }

        *result_image->pixels[i].alpha = *image->pixels[i].alpha;
    }
    
    return 0;
}


