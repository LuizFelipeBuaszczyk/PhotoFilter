#include <emscripten.h>
#include <stdint.h>

#include "arithmetic.h"
#include "invertion.h"
#include "convolution.h"
#include "grayscale.h"
#include "segmentation.h"
#include "border.h"

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

