#include <emscripten.h>
#include <stdint.h>

#include "arithmetic.h"
#include "invertion.h"
#include "convolution.h"
#include "grayscale.h"
#include "segmentation.h"
#include "border.h"
#include "logic.h"
#include "linear.h"
#include "histogram.h"
#include "morphology.h"

#include "types.h"


int buffer_size_is_valid(int size){
    return size % 4 == 0 ? 0 : 1;
} 


EMSCRIPTEN_KEEPALIVE
int image_add_value(uint8_t *buffer, int size, int value) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }

    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }
    
    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;

    pixel_count=0;
    Pixel result_pixels[size_pixels_array];
    for(int i=size; i<size+size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        result_pixels[pixel_count++] = px;
    }
    
    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;
    
    int result = add_value(value, &image, &result_image);
    if (result != 0) return -1;

    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_subt_value(uint8_t *buffer, int size, int value) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }

    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }
    
    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;

    pixel_count=0;
    Pixel result_pixels[size_pixels_array];

    for(int i=size; i<size+size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        result_pixels[pixel_count++] = px;
    }
    
    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = subt_value(value, &image, &result_image);
    if (result != 0) return -1;

    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_multiply_value(uint8_t *buffer, int size, int value) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }

    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }
    
    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;

    pixel_count=0;
    Pixel result_pixels[size_pixels_array];

    for(int i=size; i<size+size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        result_pixels[pixel_count++] = px;
    }
    
    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = multiply_value(value, &image, &result_image);
    if(result != 0) return -1;

    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_div_value(uint8_t *buffer, int size, int value) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }

    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }
    
    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;

    pixel_count=0;
    Pixel result_pixels[size_pixels_array];

    for(int i=size; i<size+size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        result_pixels[pixel_count++] = px;
    }
    
    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = div_value(value, &image, &result_image);
    if (result != 0) return -1;

    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_invert_horizontal(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = invert_horizontal(&image, &result_image);

    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_invert_vertical(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = invert_vertical(&image, &result_image);

    if (result != 0) {
        return -1;
    }
    
    return size;
}


EMSCRIPTEN_KEEPALIVE
int image_convolution_average(uint8_t *buffer, int size, int kernel_size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = convolution_average(&image, kernel_size, &result_image);

    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_convolution_min(uint8_t *buffer, int size, int kernel_size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = convolution_min(&image, kernel_size, &result_image);

    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_convolution_max(uint8_t *buffer, int size, int kernel_size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = convolution_max(&image, kernel_size, &result_image);

    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_convolution_median(uint8_t *buffer, int size, int kernel_size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = convolution_median(&image, kernel_size, &result_image);

    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_convolution_order(uint8_t *buffer, int size, int kernel_size, int order_value) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = convolution_order(&image, kernel_size, order_value, &result_image);

    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_convolution_conservative_smoothing(uint8_t *buffer, int size, int kernel_size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = convolution_conservative_smoothing(&image, kernel_size, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_convolution_gaussian(uint8_t *buffer, int size, int kernel_size, int sigma) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = convolution_gaussian(&image, kernel_size, sigma, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_convert_to_grayscale(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = grayscale_convertion_average(&image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_convert_to_binaryscale(uint8_t *buffer, int size, int treshold) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = segmentation_treshold(&image, &result_image, treshold);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_border_detection_prewit(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = border_detection_prewit(&image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_border_detection_sobel(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = border_detection_sobel(&image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_border_detection_laplacian(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = border_detection_lapaclian(&image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_add_image(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 1
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Image 2
    Pixel pixels_to_add[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_to_add[pixel_count++] = px;
    }

    Image image_to_add;
    image_to_add.rows = 250;
    image_to_add.columns = 250;
    image_to_add.pixels = (Pixel *) &pixels_to_add;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = add_image(&image, &image_to_add, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

EMSCRIPTEN_KEEPALIVE
int image_subt_image(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 1
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Image 2
    Pixel pixels_to_subt[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_to_subt[pixel_count++] = px;
    }

    Image image_to_subt;
    image_to_subt.rows = 250;
    image_to_subt.columns = 250;
    image_to_subt.pixels = (Pixel *) &pixels_to_subt;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = subt_image(&image, &image_to_subt, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

EMSCRIPTEN_KEEPALIVE
int image_logic_and_image(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 1
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Image 2
    Pixel pixels_to_and[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_to_and[pixel_count++] = px;
    }

    Image image_to_and;
    image_to_and.rows = 250;
    image_to_and.columns = 250;
    image_to_and.pixels = (Pixel *) &pixels_to_and;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = logic_and(&image, &image_to_and, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

EMSCRIPTEN_KEEPALIVE
int image_logic_or_image(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 1
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Image 2
    Pixel pixels_second_image[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_second_image[pixel_count++] = px;
    }

    Image second_image;
    second_image.rows = 250;
    second_image.columns = 250;
    second_image.pixels = (Pixel *) &pixels_second_image;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = logic_or(&image, &second_image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

EMSCRIPTEN_KEEPALIVE
int image_logic_xor_image(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 1
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Image 2
    Pixel pixels_second_image[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_second_image[pixel_count++] = px;
    }

    Image second_image;
    second_image.rows = 250;
    second_image.columns = 250;
    second_image.pixels = (Pixel *) &pixels_second_image;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = logic_xor(&image, &second_image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

EMSCRIPTEN_KEEPALIVE
int image_logic_not(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
      
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = logic_not(&image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_linear_average_image(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 1
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Image 2
    Pixel pixels_second_image[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_second_image[pixel_count++] = px;
    }

    Image second_image;
    second_image.rows = 250;
    second_image.columns = 250;
    second_image.pixels = (Pixel *) &pixels_second_image;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = linear_average(&image, &second_image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

EMSCRIPTEN_KEEPALIVE
int image_linear_blending_image(uint8_t *buffer, int size, float value) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 1
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Image 2
    Pixel pixels_second_image[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_second_image[pixel_count++] = px;
    }

    Image second_image;
    second_image.rows = 250;
    second_image.columns = 250;
    second_image.pixels = (Pixel *) &pixels_second_image;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = linear_blending(&image, &second_image, value, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

EMSCRIPTEN_KEEPALIVE
int image_histogram_equalize(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 1
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = equalize_histogram(&image, &result_image);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_morphology_dilation(uint8_t *buffer, int size, int kernel_size, int kernel_type) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = morpho_dilation(&image, &result_image, kernel_size, kernel_type);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_morphology_erosion(uint8_t *buffer, int size, int kernel_size, int kernel_type) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = morpho_erosion(&image, &result_image, kernel_size, kernel_type);
    if (result != 0) {
        return -1;
    }
    
    return size;
}

EMSCRIPTEN_KEEPALIVE
int image_morphology_opening(uint8_t *buffer, int size, int kernel_size, int kernel_type) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
     
    // Image Auxiliar
    Pixel pixels_aux[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_aux[pixel_count++] = px;
    }

    Image image_aux;
    image_aux.rows = 250;
    image_aux.columns = 250;
    image_aux.pixels = (Pixel *) &pixels_aux;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = morpho_opening(&image, &image_aux, &result_image, kernel_size, kernel_type);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

EMSCRIPTEN_KEEPALIVE
int image_morphology_closing(uint8_t *buffer, int size, int kernel_size, int kernel_type) {
    if (buffer_size_is_valid(size) != 0) {
        return -1;
    }     
    
    // Image 
    int size_pixels_array = size / 4;
    int pixel_count = 0;
    Pixel pixels[size_pixels_array];

    for(int i=0; i<size;){
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];
    
        pixels[pixel_count++] = px;
    }

    Image image;
    image.rows = 250;
    image.columns = 250;
    image.pixels = (Pixel *)&pixels;
     
    // Image Auxiliar
    Pixel pixels_aux[size_pixels_array];
    pixel_count = 0;
    for (int i=size; i<size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        pixels_aux[pixel_count++] = px;
    }

    Image image_aux;
    image_aux.rows = 250;
    image_aux.columns = 250;
    image_aux.pixels = (Pixel *) &pixels_aux;
    
    // Result Image
    Pixel result_pixels[size_pixels_array];
    pixel_count = 0;
    for (int i=size+size; i<size+size+size;) {
        Pixel px;
        px.red = &buffer[i++];
        px.green = &buffer[i++];
        px.blue = &buffer[i++];
        px.alpha = &buffer[i++];

        result_pixels[pixel_count++] = px;
    }

    Image result_image;
    result_image.rows = 250;
    result_image.columns = 250;
    result_image.pixels = (Pixel *) &result_pixels;

    int result = morpho_closing(&image, &image_aux, &result_image, kernel_size, kernel_type);
    if (result != 0) {
        return -1;
    }
    
    return size+size;
}

