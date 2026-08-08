#ifndef MORPHOLOGY
#define MORPHOLOGY

#include "types.h"
#include "utils.h"
#include "segmentation.h"
#include "arithmetic.h"

int morpho_dilation(Image *image, Image *result_image, int kernel_size, int kernel_type);
int morpho_erosion (Image *image, Image *result_image, int kernel_size, int kernel_type);
int morpho_opening (Image *image, Image *aux_image, Image *result_image, int kernel_size, int kernel_type);
int morpho_closing (Image *image, Image *aux_image, Image *result_image, int kernel_size, int kernel_type);
int morpho_outline (Image *image, Image *aux_image, Image *result_image, int kernel_size, int kernel_type);

#endif
