#include "utils.h"

#include "stdbool.h"

bool is_valid(int x, int y, int max_x, int max_y) {
    return x >=0 && y >= 0 && x < max_x && y < max_y;
}


