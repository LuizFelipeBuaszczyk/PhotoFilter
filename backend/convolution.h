#include <stdint.h>
#include <math.h>

#include "types.h"
#include "utils.h"

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

uint8_t* find_median_value(uint8_t **values, int size) {
    
    for (int i=0; i<size; i++) 
    {
        uint8_t *aux = values[i];

        for (int j=i; j<size; j++) {
            if(*aux>*values[j]) {
                values[i] = values[j];
                values[j] = aux;
                aux = values[i];
            }
        }


    }

    if (size % 2 == 0) return values[size/2];

    return values[size/2 + 1];
}

int convolution_median(Image *image, int kernel_size, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    int total_pixel_in_kernel = kernel_size * kernel_size;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            uint8_t *red_values[kernel_size*kernel_size];
            uint8_t *green_values[kernel_size*kernel_size];
            uint8_t *blue_values[kernel_size*kernel_size];
            int pixel_count = 0;

            for (int x=kernel_size / 2 * -1 + i; x<=kernel_size / 2 + i; x++) {
                for (int y=kernel_size / 2 * -1 + j; y<=kernel_size / 2 + j; y++) {
                    if (is_valid(x, y, height, width)) {
                       red_values[pixel_count] = image->pixels[x*width+y].red;
                       green_values[pixel_count] = image->pixels[x*width+y].green;
                       blue_values[pixel_count] = image->pixels[x*width+y].blue;
                       pixel_count++;
                    }
                }
            }         

            *result_image->pixels[i * width + j].red = *find_median_value(red_values, pixel_count);
            *result_image->pixels[i * width + j].green = *find_median_value(green_values, pixel_count);
            *result_image->pixels[i * width + j].blue = *find_median_value(blue_values, pixel_count);
            *result_image->pixels[i * width + j].alpha = *image->pixels[i * width + j].alpha;
         }
    }

    return 0;
}

uint8_t* find_order_value(uint8_t **values, int size, int value) {
    
    for (int i=0; i<size; i++) 
    {
        uint8_t *aux = values[i];

        for (int j=i; j<size; j++) {
            if(*aux>*values[j]) {
                values[i] = values[j];
                values[j] = aux;
                aux = values[i];
            }
        }


    }

    return values[value];
}

bool is_order_value_valid(int kernel_size, int order_value) {
    return order_value >= 0 && order_value < kernel_size * kernel_size;
}

int convolution_order(Image *image, int kernel_size, int order_value, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    if (!is_order_value_valid(kernel_size, order_value)) {
        return 1;
    }

    int total_pixel_in_kernel = kernel_size * kernel_size;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            uint8_t *red_values[kernel_size*kernel_size];
            uint8_t *green_values[kernel_size*kernel_size];
            uint8_t *blue_values[kernel_size*kernel_size];
            int pixel_count = 0;

            for (int x=kernel_size / 2 * -1 + i; x<=kernel_size / 2 + i; x++) {
                for (int y=kernel_size / 2 * -1 + j; y<=kernel_size / 2 + j; y++) {
                    if (is_valid(x, y, height, width)) {
                       red_values[pixel_count] = image->pixels[x*width+y].red;
                       green_values[pixel_count] = image->pixels[x*width+y].green;
                       blue_values[pixel_count] = image->pixels[x*width+y].blue;
                       pixel_count++;
                    }
                }
            }         

            *result_image->pixels[i * width + j].red = *find_order_value(red_values, pixel_count, order_value);
            *result_image->pixels[i * width + j].green = *find_order_value(green_values, pixel_count, order_value);
            *result_image->pixels[i * width + j].blue = *find_order_value(blue_values, pixel_count, order_value);
            *result_image->pixels[i * width + j].alpha = *image->pixels[i * width + j].alpha;
         }
    }

    return 0;
}

void sort_pixels_array(uint8_t **array, int size) {

    for (int i=0; i<size; i++) {
        uint8_t *aux = array[i];

        for (int j=i; j<size; j++) {
            if(*aux>*array[j]) {
                array[i] = array[j];
                array[j] = aux;
                aux = array[i];
            }
        }
    }

}

int convolution_conservative_smoothing(Image *image, int kernel_size,Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    int total_pixel_in_kernel = kernel_size * kernel_size;

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            uint8_t *red_values[kernel_size*kernel_size];
            uint8_t *green_values[kernel_size*kernel_size];
            uint8_t *blue_values[kernel_size*kernel_size];
            int pixel_count = 0;

            for (int x=kernel_size / 2 * -1 + i; x<=kernel_size / 2 + i; x++) {
                for (int y=kernel_size / 2 * -1 + j; y<=kernel_size / 2 + j; y++) {
                    if (is_valid(x, y, height, width)) {
                       red_values[pixel_count] = image->pixels[x*width+y].red;
                       green_values[pixel_count] = image->pixels[x*width+y].green;
                       blue_values[pixel_count] = image->pixels[x*width+y].blue;
                       pixel_count++;
                    }
                }
            }         
            
            sort_pixels_array(red_values, pixel_count);
            sort_pixels_array(green_values, pixel_count);
            sort_pixels_array(blue_values, pixel_count);

            uint8_t min_red = *red_values[0];
            uint8_t max_red = *red_values[pixel_count-1];


            if (*image->pixels[i * width + j].red > max_red) {
                *result_image->pixels[i * width + j].red = max_red;
            } 
            else if (*image->pixels[i * width + j].red < min_red) {
                *result_image->pixels[i * width + j].red = min_red;
            } else {
                *result_image->pixels[i * width + j].red = *image->pixels[i * width + j].red; 
            }

            uint8_t min_green = *green_values[0];
            uint8_t max_green = *green_values[pixel_count-1];

            if (*image->pixels[i * width + j].green > max_green) {
                *result_image->pixels[i * width + j].green = max_green; 
            } 
            else if (*image->pixels[i * width + j].green < min_green) {
                *result_image->pixels[i * width + j].green = min_green; 
            } else {
                *result_image->pixels[i * width + j].green = *image->pixels[i * width + j].green; 
            }

            uint8_t min_blue = *green_values[0];
            uint8_t max_blue = *green_values[pixel_count-1];

            if (*image->pixels[i * width + j].blue > max_blue) {
                *result_image->pixels[i * width + j].blue = max_blue; 
            } 
            else if (*image->pixels[i * width + j].blue < min_blue) {
                *result_image->pixels[i * width + j].blue = min_blue; 
            } else {
                *result_image->pixels[i * width + j].blue = *image->pixels[i * width + j].blue; 
            }

            *result_image->pixels[i * width + j].alpha = *image->pixels[i * width + j].alpha;
         }
    }

    return 0;
}

void set_gaussian_model(int kernel_size, int sigma, float *gaussian_kernel) {
    float pi = 3.14;
    int center = kernel_size / 2;

    float total = 0;
    for (int i=0; i<kernel_size; i++) {
        for (int j=0; j<kernel_size; j++) {
            int x = i - center;
            int y = j - center;

            gaussian_kernel[i*kernel_size+j] = ((1.0 / (pi * (sigma * sigma))) * expf(-(x * x + y * y) / (2.0 * sigma * sigma)));
            total += gaussian_kernel[i*kernel_size+j];
        }
    }

    for (int i=0; i<kernel_size; i++) {
        for (int j=0; j<kernel_size; j++) {
            gaussian_kernel[i*kernel_size+j] /= total;
        }
    }
}

int convolution_gaussian(Image *image, int kernel_size,  int sigma, Image *result_image) {
    int width = image->columns;
    int height = image->rows;

    int total_pixel_in_kernel = kernel_size * kernel_size;

    float gaussian_kernel[total_pixel_in_kernel];
    set_gaussian_model(kernel_size, sigma, gaussian_kernel);

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            float sum_red, sum_green, sum_blue;
            sum_red = sum_green = sum_blue = 0;
            int pixel_count = 0;

            for (int x=kernel_size / 2 * -1 + i, aux_x=0; x<=kernel_size / 2 + i; x++, aux_x++) {
                for (int y=kernel_size / 2 * -1 + j, aux_y=0; y<=kernel_size / 2 + j; y++, aux_y++) {
                    if (is_valid(x, y, height, width)) {
                        sum_red += (*image->pixels[x*width+y].red * gaussian_kernel[aux_x*kernel_size+aux_y]);
                        sum_green += (*image->pixels[x*width+y].green * gaussian_kernel[aux_x*kernel_size+aux_y]);
                        sum_blue += (*image->pixels[x*width+y].blue * gaussian_kernel[aux_x*kernel_size+aux_y]);
                    } else {
                        sum_red += (*image->pixels[i*width+j].red * gaussian_kernel[aux_x*kernel_size+aux_y]);
                        sum_green += (*image->pixels[i*width+j].green * gaussian_kernel[aux_x*kernel_size+aux_y]);
                        sum_blue += (*image->pixels[i*width+j].blue * gaussian_kernel[aux_x*kernel_size+aux_y]);
                    }
                }
            }

            *result_image->pixels[i*width+j].red = sum_red > 255 ? 255 : sum_red;
            *result_image->pixels[i*width+j].green = sum_green > 255 ? 255 : sum_green;
            *result_image->pixels[i*width+j].blue = sum_blue > 255 ? 255 : sum_blue;
            *result_image->pixels[i*width+j].alpha = *image->pixels[i*width+j].alpha;
        }
    }

    return 0;
}
