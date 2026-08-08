#ifndef LINEAR
#define LINEAR

#include "types.h"

int linear_average(Image *image, Image *second_image, Image *result_image);
int linear_blending(Image *image, Image *second_image, float value, Image *result_image);

#endif
