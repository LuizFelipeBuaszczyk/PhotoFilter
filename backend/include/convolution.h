#ifndef CONVOLUTION
#define CONVOLUTION

#include <stdint.h>
#include "types.h"

int convolution_average(Image *image, int kernel_size, Image *result_image);
int convolution_min(Image *image, int kernel_size, Image *result_image);
int convolution_max(Image *image, int kernel_size, Image *result_image);
int convolution_median(Image *image, int kernel_size, Image *result_image);
int convolution_order(Image *image, int kernel_size, int order_value, Image *result_image);
int convolution_conservative_smoothing(Image *image, int kernel_size,Image *result_image);
int convolution_gaussian(Image *image, int kernel_size,  int sigma, Image *result_image);

#endif
