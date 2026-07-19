#include "types.h"

bool is_border(int x, int y, int max_x, int max_y) {
    return x == 0 || y == 0 || x == max_x || y == max_y;
}

bool is_valid(int x, int y, int max_x, int max_y) {
    return x >=0 && y >= 0 && x < max_x && y < max_y;
}

int convolution_average(Image *image, int kernel_size, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    int total_pixel_in_kernel = kernel_size * kernel_size;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int sum_red = 0;            
            int sum_green = 0;            
            int sum_blue = 0;            
            
            for (int x=kernel_size / 2 * -1 + i; x<=kernel_size / 2 + i; x++) {
                for (int y=kernel_size / 2 * -1 + j; y<=kernel_size / 2 + j; y++) {
                    if (is_valid(x, y, height, width)) {
                        sum_red += *image->pixels[x * width + y].red;
                        sum_green += *image->pixels[x * width + y].green;
                        sum_blue += *image->pixels[x * width + y].blue;
                    } else {
                        sum_red += *image->pixels[i * width + j].red;
                        sum_green += *image->pixels[i * width + j].green;
                        sum_blue += *image->pixels[i * width + j].blue;
                    }
                }
            }

            *result_image->pixels[i * width + j].red = sum_red / total_pixel_in_kernel;
            *result_image->pixels[i * width + j].green = sum_green / total_pixel_in_kernel;
            *result_image->pixels[i * width + j].blue = sum_blue / total_pixel_in_kernel;
            *result_image->pixels[i * width + j].alpha = *image->pixels[i * width + j].alpha;
         }
    }

    return 0;
}

int convolution_min(Image *image, int kernel_size, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    int total_pixel_in_kernel = kernel_size * kernel_size;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int min_red = 255;            
            int min_green = 255;            
            int min_blue = 255;            
            
            for (int x=kernel_size / 2 * -1 + i; x<=kernel_size / 2 + i; x++) {
                for (int y=kernel_size / 2 * -1 + j; y<=kernel_size / 2 + j; y++) {
                    if (is_valid(x, y, height, width)) {
                        if (min_red > *image->pixels[x*width+y].red) {
                            min_red = *image->pixels[x*width+y].red;
                        }
                        if (min_green > *image->pixels[x*width+y].green) {
                            min_green = *image->pixels[x * width + y].green;

                        }
                        if (min_blue > *image->pixels[x*width+y].blue) {
                            min_blue = *image->pixels[x * width + y].blue;
                        }
                    }
                }
            }

            *result_image->pixels[i * width + j].red = min_red;
            *result_image->pixels[i * width + j].green = min_green;
            *result_image->pixels[i * width + j].blue = min_blue;
            *result_image->pixels[i * width + j].alpha = *image->pixels[i * width + j].alpha;
         }
    }

    return 0;
}

int convolution_max(Image *image, int kernel_size, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    int total_pixel_in_kernel = kernel_size * kernel_size;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int max_red = 0;            
            int max_green = 0;            
            int max_blue = 0;            
            
            for (int x=kernel_size / 2 * -1 + i; x<=kernel_size / 2 + i; x++) {
                for (int y=kernel_size / 2 * -1 + j; y<=kernel_size / 2 + j; y++) {
                    if (is_valid(x, y, height, width)) {
                        if (max_red < *image->pixels[x*width+y].red) {
                            max_red = *image->pixels[x*width+y].red;
                        }
                        if (max_green < *image->pixels[x*width+y].green) {
                            max_green = *image->pixels[x * width + y].green;

                        }
                        if (max_blue < *image->pixels[x*width+y].blue) {
                            max_blue = *image->pixels[x * width + y].blue;
                        }
                    }
                }
            }

            *result_image->pixels[i * width + j].red = max_red;
            *result_image->pixels[i * width + j].green = max_green;
            *result_image->pixels[i * width + j].blue = max_blue;
            *result_image->pixels[i * width + j].alpha = *image->pixels[i * width + j].alpha;
         }
    }

    return 0;
}
