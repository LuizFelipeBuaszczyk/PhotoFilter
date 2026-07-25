#include "types.h"

#include "grayscale.h"

int segmentation_treshold(Image *image, Image *result_image, int threshold) {
    
    grayscale_convertion_average(image, image);

    for (int i=0; i<image->rows; i++){
        for (int j=0; j<image->columns; j++) {
           *result_image->pixels[i*image->rows+j].red = *image->pixels[i*image->rows+j].red > threshold ? 255 : 0;
           *result_image->pixels[i*image->rows+j].green = *image->pixels[i*image->rows+j].green > threshold ? 255 : 0;
           *result_image->pixels[i*image->rows+j].blue = *image->pixels[i*image->rows+j].blue > threshold ? 255 : 0;
           *result_image->pixels[i*image->rows+j].alpha = *image->pixels[i*image->rows+j].alpha;
        }
    }

    return 0;
}
