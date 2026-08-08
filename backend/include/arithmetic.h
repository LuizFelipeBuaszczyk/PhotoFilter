#ifndef ARITHMETIC
#define ARITHMETIC

#include "types.h"

// Value
int add_value (uint8_t value, Image *image, Image *result_image);
int subt_value (uint8_t value, Image *image, Image *result_image);
int multiply_value (uint8_t value, Image *image, Image *result_image);
int div_value (uint8_t value, Image *image, Image *result_image);

// 2 Images
int add_image (Image *image, Image *image_to_add, Image *result_image);
int subt_image (Image *image, Image *image_to_subt, Image *result_image);

#endif
