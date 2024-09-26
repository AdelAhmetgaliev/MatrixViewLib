#include <stdlib.h>

#include "matrixview.h"

int main(void) {
    double data1[] = { 
        1.0, 0.0,
        0.0, 1.0,
    };

    double data2[] = {
        2.0, 3.0,
        0.0, 5.0,
    };

    
    MatrixView matrix1 = mv_new(data1, 2, 2);
    MatrixView matrix2 = mv_new(data2, 2, 2);

    mv_sumto(matrix2, matrix1);
    mv_print(matrix2);

    return EXIT_SUCCESS;
}
