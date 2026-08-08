#ifndef BORDER
#define BORDER

#include "types.h"

int border_detection_prewit(Image *image, Image *result_image);
int border_detection_sobel(Image *image, Image *result_image);
int border_detection_lapaclian(Image *image, Image *result_image);

#endif
