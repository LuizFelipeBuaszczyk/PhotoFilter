#include "types.h"

int linear_average(Image *image, Image *second_image, Image *result_image) {
    int width = image->columns;
    int height = image->rows;


    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
           int aux;
            
           aux = *image->pixels[i*height+j].red + *second_image->pixels[i*height+j].red;
           *result_image->pixels[i*height+j].red = aux/2;

           aux = *image->pixels[i*height+j].green + *second_image->pixels[i*height+j].green;
           *result_image->pixels[i*height+j].green = aux/2;

           aux = *image->pixels[i*height+j].blue + *second_image->pixels[i*height+j].blue;
           *result_image->pixels[i*height+j].blue = aux/2;

           *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }
    
    return 0;
}
