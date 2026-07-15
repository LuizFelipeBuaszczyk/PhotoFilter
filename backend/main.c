#include <emscripten.h>
#include <stdint.h>

#include "arithmetic.h"
#include "invertion.h"


int buffer_size_is_valid(int size){
    return size % 4 == 0 ? 0 : 1;
} 


EMSCRIPTEN_KEEPALIVE
int image_add_value(uint8_t *buffer, int size, int value) {
    if (buffer_size_is_valid(size) != 0) {
        return 1;
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
    return add_value(value, &image);
}

EMSCRIPTEN_KEEPALIVE
int image_subt_value(uint8_t *buffer, int size, int value) {
    if (buffer_size_is_valid(size) != 0) {
        return 1;
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
    return subt_value(value, &image);
}

EMSCRIPTEN_KEEPALIVE
int image_multiply_value(uint8_t *buffer, int size, int value) {
    if (buffer_size_is_valid(size) != 0) {
        return 1;
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
    return multiply_value(value, &image);
}

EMSCRIPTEN_KEEPALIVE
int image_div_value(uint8_t *buffer, int size, int value) {
    if (buffer_size_is_valid(size) != 0) {
        return 1;
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
    return div_value(value, &image);
}

EMSCRIPTEN_KEEPALIVE
int image_invert_horizontal(uint8_t *buffer, int size) {
    if (buffer_size_is_valid(size) != 0) {
        return 1;
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
       
    return invert_horizontal(&image);
}
