
#include "types.h"
#include "grayscale.h"

#include "utils.h"
#include <math.h>

int border_detection_prewit(Image *image, Image *result_image){
    /* derivate X || derivate Y
     * [-1, 0, 1] || [-1,-1,-1]
     * [-1, 0, 1] || [ 0, 0, 0]
     * [-1, 0, 1] || [ 1, 1, 1]
     */

    int width = image->columns;
    int height = image->rows;

    
    int x_derivate[3][3], y_derivate[3][3];
 
    x_derivate[0][0] = -1; x_derivate[0][1] = 0; x_derivate[0][2] = 1;
    x_derivate[1][0] = -1; x_derivate[1][1] = 0; x_derivate[1][2] = 1;
    x_derivate[2][0] = -1; x_derivate[2][1] = 0; x_derivate[2][2] = 1;

    y_derivate[0][0] = -1; y_derivate[0][1] = -1; y_derivate[0][2] = -1;
    y_derivate[1][0] =  0; y_derivate[1][1] =  0; y_derivate[1][2] =  0;
    y_derivate[2][0] =  1; y_derivate[2][1] =  1; y_derivate[2][2] =  1;

    grayscale_convertion_average(image, image);

    for (int i=0; i<image->rows; i++) {
        for (int j=0; j<image->columns; j++) {
            float value_x, value_y;
            value_x = value_y = 0;
            
            for (int x=i-1, pos_x=0; x<=i+1; x++, pos_x++) {
                for (int y=j-1, pos_y=0; y<=j+1; y++, pos_y++) {
                    if (is_valid(x, y, height, width)) {
                        value_x += *image->pixels[x*height+y].red * x_derivate[pos_x][pos_y];
                        value_y += *image->pixels[x*height+y].red * y_derivate[pos_x][pos_y];
                    } else {
                        value_x += *image->pixels[i*height+j].red * x_derivate[pos_x][pos_y];
                        value_y += *image->pixels[i*height+j].red * y_derivate[pos_x][pos_y];
                    }
                }
            }
            uint8_t result_value = sqrt((value_x*value_x) + (value_y*value_y));
            *result_image->pixels[i*height+j].red = result_value;
            *result_image->pixels[i*height+j].green = result_value;
            *result_image->pixels[i*height+j].blue = result_value;
            *result_image->pixels[i*height+j].alpha = *image->pixels[i*height+j].alpha;
         }
    }

    return 0;
}
