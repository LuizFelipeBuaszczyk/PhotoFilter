

#include "types.h"
#include "utils.h"
#include "segmentation.h"

int morpho_dilation(Image *image, Image *result_image, int kernel_size, int kernel_type) {
    int width = image->columns;
    int height = image->rows;
    int padding = kernel_size / 2;
    
    segmentation_treshold(image, image, 127);
    
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            bool pixel_found = false; 
            switch(kernel_type) {
                case 1:
                    for (int x=i-padding; x<=i+padding; x++) {
                        for (int y=j-padding; y<=j+padding; y++) {
                            if (!is_valid(x, y, width, height)) continue;

                            if (*image->pixels[x*height+y].red == 255) {
                                pixel_found = true;
                                break;
                            }
                        }

                        if (pixel_found) break;
                    }
                    break;
                case 2:
                    for (int x=i-padding; x<=i+padding; x++) {
                        int dx = abs(x-i);

                        int max_dy = padding - dx;

                        for (int y=j-max_dy; y<=j+max_dy; y++) {
                            if (!is_valid(x, y, width, height)) continue;

                            if (*image->pixels[x*height+y].red == 255) {
                                pixel_found = true;
                                break;
                            }
                        }
                        if (pixel_found) break;
                    }
                    break;
                case 3:
                    for (int y=j-padding; y<=j+padding; y++) {
                        if (!is_valid(y, i, width, height)) continue;

                        if (*image->pixels[i*height+y].red == 255) {
                            pixel_found = true;
                            break;
                        }
                    }
                    break;
                case 4:
                    for (int x=i-padding; x<=i+padding; x++) {
                        if (!is_valid(j, x, width, height)) continue;

                        if (*image->pixels[x*height+j].red == 255) {
                            pixel_found = true;
                            break;
                        }
                    }
                    break;
                default:
                    return 1;

            }

            *result_image->pixels[i*height+j].red = pixel_found ? 255 : 0;
            *result_image->pixels[i*height+j].green = pixel_found ? 255 : 0;
            *result_image->pixels[i*height+j].blue = pixel_found ? 255 : 0;
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }

    return 0;
}
