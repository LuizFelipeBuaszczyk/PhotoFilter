#include "types.h"

int invert_horizontal(Image *image) {
    int width = image->columns;
    int heigth = image->rows;

    for (int i=0; i<image->rows; i++){
        for (int j=0; j<image->columns/2; j++) {
             
            *image->pixels[i * width + j].red = *image->pixels[i * width + width -j - 1].red;
            *image->pixels[i * width + j].green = *image->pixels[i * width + width - j - 1].green;
            *image->pixels[i * width + j].blue = *image->pixels[i * width + width - j - 1].blue;
            *image->pixels[i * width + j].alpha = *image->pixels[i * width + width - j - 1].alpha;

            *image->pixels[i * width + width - j - 1].red = *image->pixels[i * width + j].red;
            *image->pixels[i * width + width - j - 1].green = *image->pixels[i * width + j].green;
            *image->pixels[i * width + width - j - 1].blue = *image->pixels[i * width + j].blue;
            *image->pixels[i * width + width - j - 1].alpha = *image->pixels[i * width + j].alpha;

           // Pixel aux = *last_pixel;
           // *last_pixel = *first_pixel;
           // *first_pixel = aux;
       }
    }

    return 0;
}

