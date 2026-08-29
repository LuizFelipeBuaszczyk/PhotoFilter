#include "histogram.h"

#include "types.h"
#include "grayscale.h"

Status get_histogram(Image *image, int *histogram) {
    int width = image->columns;
    int height = image->rows;
    
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            histogram[*image->pixels[i*height+j].red]++;
        }
    }

    return OK;
}


Status equalize_histogram(Image *image, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    grayscale_convertion_average(image, image);

    int histogram[256] = {0};
    get_histogram(image, histogram);
    
    int cfd[256] = {0};
    uint8_t new_pixel_values[256];
    for (int i=0; i<256; i++) {
        if (i==0) {
            cfd[0] = histogram[0];
        } else {
            cfd[i] = histogram[i] + cfd[i-1];
        }

        float upper = cfd[i] - cfd[0] > 0 ? cfd[i] - cfd[0] : 1;
        float under = width * height - cfd[0];

        float aux = upper/under;
        new_pixel_values[i] = aux * 255;
    }


    for (int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            *result_image->pixels[i*height+j].red = new_pixel_values[*image->pixels[i*height+j].red];
            *result_image->pixels[i*height+j].green = new_pixel_values[*image->pixels[i*height+j].red];
            *result_image->pixels[i*height+j].blue = new_pixel_values[*image->pixels[i*height+j].red];
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }

    return OK;
}
