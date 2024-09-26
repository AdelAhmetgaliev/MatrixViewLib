#include <stdlib.h>

#include "matrixview.h"

int main(void) {
    double data[] = { 
        1.0, 0.0,
        0.0, 1.0,
    };
    
    MatrixView matrix_2x2 = mv_new(data, 2, 2);
    MatrixView matrix_1x4 = mv_new(data, 1, 4);

    MV_GET(matrix_1x4, 0, 1) = 2.0;
    
    mv_print(matrix_2x2);

    return EXIT_SUCCESS;
}
