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
            bool dilation_operation = false; 
            switch(kernel_type) {
                case 1:
                    for (int x=i-padding; x<=i+padding; x++) {
                        for (int y=j-padding; y<=j+padding; y++) {
                            if (!is_valid(x, y, width, height)) continue;

                            if (*image->pixels[x*height+y].red == 255) {
                                dilation_operation = true;
                                break;
                            }
                        }

                        if (dilation_operation) break;
                    }
                    break;
                case 2:
                    for (int x=i-padding; x<=i+padding; x++) {
                        int dx = abs(x-i);

                        int max_dy = padding - dx;

                        for (int y=j-max_dy; y<=j+max_dy; y++) {
                            if (!is_valid(x, y, width, height)) continue;

                            if (*image->pixels[x*height+y].red == 255) {
                                dilation_operation = true;
                                break;
                            }
                        }
                        if (dilation_operation) break;
                    }
                    break;
                case 3:
                    for (int y=j-padding; y<=j+padding; y++) {
                        if (!is_valid(y, i, width, height)) continue;

                        if (*image->pixels[i*height+y].red == 255) {
                            dilation_operation = true;
                            break;
                        }
                    }
                    break;
                case 4:
                    for (int x=i-padding; x<=i+padding; x++) {
                        if (!is_valid(j, x, width, height)) continue;

                        if (*image->pixels[x*height+j].red == 255) {
                            dilation_operation = true;
                            break;
                        }
                    }
                    break;
                default:
                    return 1;

            }

            *result_image->pixels[i*height+j].red = dilation_operation ? 255 : 0;
            *result_image->pixels[i*height+j].green = dilation_operation ? 255 : 0;
            *result_image->pixels[i*height+j].blue = dilation_operation ? 255 : 0;
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }

    return 0;
}

int morpho_erosion (Image *image, Image *result_image, int kernel_size, int kernel_type) {
    int width = image->columns;
    int height = image->rows;
    int padding = kernel_size / 2;
    
    segmentation_treshold(image, image, 127);
    
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            bool erosion_operation = true;
            switch(kernel_type) {
                case 1:
                    for (int x=i-padding; x<=i+padding; x++) {
                        for (int y=j-padding; y<=j+padding; y++) {
                            if (!is_valid(x, y, width, height)) continue;

                            if (*image->pixels[x*height+y].red != 255) {
                                erosion_operation = false;
                                break;
                            }
                        }

                        if (!erosion_operation) break;
                    }
                    break;
                case 2:
                    for (int x=i-padding; x<=i+padding; x++) {
                        int dx = abs(x-i);

                        int max_dy = padding - dx;

                        for (int y=j-max_dy; y<=j+max_dy; y++) {
                            if (!is_valid(x, y, width, height)) continue;

                            if (*image->pixels[x*height+y].red != 255) {
                                erosion_operation = false;
                                break;
                            }
                        }
                        if (!erosion_operation) break;
                    }
                    break;
                case 3:
                    for (int y=j-padding; y<=j+padding; y++) {
                        if (!is_valid(y, i, width, height)) continue;

                        if (*image->pixels[i*height+y].red != 255) {
                            erosion_operation = false;
                            break;
                        }
                    }
                    break;
                case 4:
                    for (int x=i-padding; x<=i+padding; x++) {
                        if (!is_valid(j, x, width, height)) continue;

                        if (*image->pixels[x*height+j].red != 255) {
                            erosion_operation = false;
                            break;
                        }
                    }
                    break;
                default:
                    return 1;

            }

            *result_image->pixels[i*height+j].red = erosion_operation ? 255 : 0;
            *result_image->pixels[i*height+j].green = erosion_operation ? 255 : 0;
            *result_image->pixels[i*height+j].blue = erosion_operation ? 255 : 0;
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }   

    return 0;
}

int morpho_opening (Image *image, Image *aux_image, Image *result_image, int kernel_size, int kernel_type) {
    int width = image->columns;
    int height = image->rows;
    int padding = kernel_size / 2;
    int total_size = width * height;
    
    morpho_erosion(image, aux_image, kernel_size, kernel_type);
    morpho_dilation(aux_image, result_image, kernel_size, kernel_type);

    return 0;
}
