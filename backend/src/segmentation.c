#include "segmentation.h"

#include "types.h"
#include "grayscale.h"

Status segmentation_treshold(Image *image, Image *result_image, int threshold) {
    
    Status result_grayscale_convertion = grayscale_convertion_average(image, image);
    if (result_grayscale_convertion != OK) return result_grayscale_convertion;

    for (int i=0; i<image->rows; i++){
        for (int j=0; j<image->columns; j++) {
           *result_image->pixels[i*image->rows+j].red = *image->pixels[i*image->rows+j].red > threshold ? 255 : 0;
           *result_image->pixels[i*image->rows+j].green = *image->pixels[i*image->rows+j].green > threshold ? 255 : 0;
           *result_image->pixels[i*image->rows+j].blue = *image->pixels[i*image->rows+j].blue > threshold ? 255 : 0;
           *result_image->pixels[i*image->rows+j].alpha = *image->pixels[i*image->rows+j].alpha;
        }
    }

    return OK;
}
