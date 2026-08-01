
#include "types.h"

#include "segmentation.h"

int logic_and(Image *image, Image *image2, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    segmentation_treshold(image, image, 127);
    segmentation_treshold(image2, image2, 127);

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            uint8_t and_operation = (*image->pixels[i*height+j].red == 255 && *image2->pixels[i*height+j].red == 255) ? 255 : 0; 

            *result_image->pixels[i*height+j].red = and_operation;
            *result_image->pixels[i*height+j].green = and_operation;
            *result_image->pixels[i*height+j].blue = and_operation;
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }
    

    return 0;
}

int logic_or(Image *image, Image *image2, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    segmentation_treshold(image, image, 127);
    segmentation_treshold(image2, image2, 127);

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            uint8_t or_operation = (*image->pixels[i*height+j].red == 255 || *image2->pixels[i*height+j].red == 255) ? 255 : 0; 

            *result_image->pixels[i*height+j].red = or_operation;
            *result_image->pixels[i*height+j].green = or_operation;
            *result_image->pixels[i*height+j].blue = or_operation;
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }
    

    return 0;
}
