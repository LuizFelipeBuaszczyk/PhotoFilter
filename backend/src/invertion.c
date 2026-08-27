#include "invertion.h"

#include "types.h"

Status invert_horizontal(Image *image, Image *result_image) {
    int width = image->columns;
    int heigth = image->rows;

    for (int i=0; i<image->rows; i++){
        for (int j=0; j<image->columns/2; j++) {
             
            *result_image->pixels[i * width + j].red = *image->pixels[i * width + width -j - 1].red;
            *result_image->pixels[i * width + j].green = *image->pixels[i * width + width - j - 1].green;
            *result_image->pixels[i * width + j].blue = *image->pixels[i * width + width - j - 1].blue;
            *result_image->pixels[i * width + j].alpha = *image->pixels[i * width + width - j - 1].alpha;

            *result_image->pixels[i * width + width - j - 1].red = *image->pixels[i * width + j].red;
            *result_image->pixels[i * width + width - j - 1].green = *image->pixels[i * width + j].green;
            *result_image->pixels[i * width + width - j - 1].blue = *image->pixels[i * width + j].blue;
            *result_image->pixels[i * width + width - j - 1].alpha = *image->pixels[i * width + j].alpha;
       }
    }

    return OK;
}

Status invert_vertical(Image *image, Image *result_image) {
    int width = image->columns;
    int heigth = image->rows;

    for (int i=0; i<image->rows/2; i++){
        for (int j=0; j<image->columns; j++) {
            *result_image->pixels[i * width + j].red = *image->pixels[width * (heigth - i) - 250 + j].red;
            *result_image->pixels[i * width + j].green = *image->pixels[width * (heigth - i) - 250 + j].green;
            *result_image->pixels[i * width + j].blue = *image->pixels[width * (heigth - i) - 250 + j].blue;
            *result_image->pixels[i * width + j].alpha = *image->pixels[width * (heigth - i) - 250 + j].alpha;

            *result_image->pixels[width * (heigth - i) - 250 + j].red = *image->pixels[i * width + j].red;
            *result_image->pixels[width * (heigth - i) - 250 + j].green = *image->pixels[i * width + j].green;
            *result_image->pixels[width * (heigth - i) - 250 + j].blue = *image->pixels[i * width + j].blue;
            *result_image->pixels[width * (heigth - i) - 250 + j].alpha = *image->pixels[i * width + j].alpha;
        }
    }

    return OK;
}

