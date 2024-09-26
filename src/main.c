#include <stdlib.h>

#include "matrixview.h"

int main(void) {
    double data1[] = { 
        1.0, 0.0,
        0.0, 1.0,
        2.0, 3.0,
    };

    double data2[] = {
        2.0, 3.0,
        0.0, 5.0,
    };

    double data3[6];
 
    MatrixView matrix1 = mv_new(data1, 3, 2);
    MatrixView matrix2 = mv_new(data2, 2, 2);
    MatrixView matrix3 = mv_new(data3, 3, 2);

    mv_dot(matrix3, matrix1, matrix2);
    mv_print(matrix3);

    return EXIT_SUCCESS;
}
