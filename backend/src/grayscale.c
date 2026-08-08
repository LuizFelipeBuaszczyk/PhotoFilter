#include "grayscale.h"

#include "types.h"
#include <stdint.h>

int grayscale_convertion_average(Image *image, Image *result_image) {

    for (int i=0; i<image->rows; i++) {
        for (int j=0; j<image->columns; j++) {
            uint8_t average = (*image->pixels[i*image->rows+j].red + *image->pixels[i*image->rows+j].green + *image->pixels[i*image->rows+j].blue)/3;
            *result_image->pixels[i*image->rows+j].red = average;
            *result_image->pixels[i*image->rows+j].green = average;
            *result_image->pixels[i*image->rows+j].blue = average;
            *result_image->pixels[i*image->rows+j].alpha = *image->pixels[i*image->rows+j].alpha;
        }
    }

    return 0;
}

