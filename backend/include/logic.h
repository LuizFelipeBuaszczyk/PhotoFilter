#ifndef LOGIC
#define LOGIC

#include "types.h"

int logic_not(Image *image, Image *result_image);
int logic_and(Image *image, Image *image2, Image *result_image);
int logic_or(Image *image, Image *image2, Image *result_image);
int logic_xor(Image *image, Image *image2, Image *result_image);

#endif
