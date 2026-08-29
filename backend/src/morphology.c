#include "morphology.h"

#include "stdlib.h"

#include "types.h"
#include "utils.h"
#include "segmentation.h"
#include "arithmetic.h"

Status morpho_dilation(Image *image, Image *result_image, int kernel_size, int kernel_type) {
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
                    return INVALID_KERNEL_TYPE;

            }

            *result_image->pixels[i*height+j].red = dilation_operation ? 255 : 0;
            *result_image->pixels[i*height+j].green = dilation_operation ? 255 : 0;
            *result_image->pixels[i*height+j].blue = dilation_operation ? 255 : 0;
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }

    return OK;
}

Status morpho_erosion (Image *image, Image *result_image, int kernel_size, int kernel_type) {
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
                    return INVALID_KERNEL_TYPE;

            }

            *result_image->pixels[i*height+j].red = erosion_operation ? 255 : 0;
            *result_image->pixels[i*height+j].green = erosion_operation ? 255 : 0;
            *result_image->pixels[i*height+j].blue = erosion_operation ? 255 : 0;
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
        }
    }   

    return OK;
}

Status morpho_opening (Image *image, Image *aux_image, Image *result_image, int kernel_size, int kernel_type) {
    int width = image->columns;
    int height = image->rows;
    int padding = kernel_size / 2;
    
    Status result_erosion = morpho_erosion(image, aux_image, kernel_size, kernel_type);
    if (result_erosion != OK) return result_erosion;

    Status result_dilation = morpho_dilation(aux_image, result_image, kernel_size, kernel_type);
    if (result_dilation != OK) return result_dilation;

    return OK;
}

Status morpho_closing (Image *image, Image *aux_image, Image *result_image, int kernel_size, int kernel_type) {
    int width = image->columns;
    int height = image->rows;
    int padding = kernel_size / 2;

    Status result_dilation = morpho_dilation(aux_image, result_image, kernel_size, kernel_type);
    if (result_dilation != OK) return result_dilation;

    Status result_erosion = morpho_erosion(image, aux_image, kernel_size, kernel_type);
    if (result_erosion != OK) return result_erosion;
    
    return OK;
}

Status morpho_outline (Image *image, Image *aux_image, Image *result_image, int kernel_size, int kernel_type) {
    int width = image->columns;
    int height = image->rows;
    int padding = kernel_size / 2;
    
    Status result_erosion =  morpho_erosion(image, aux_image, kernel_size, kernel_type);
    if (result_erosion != OK) return result_erosion;

    Status result_subt = subt_image(image, aux_image, result_image);
    if (result_subt != OK) return result_subt;

    return OK;
}
