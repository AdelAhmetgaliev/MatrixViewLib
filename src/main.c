#include <stdio.h>
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

    printf("matrix2 before copy:\n");
    mv_print(matrix2);

    mv_copy(matrix2, matrix1);

    printf("\nmatrix2 after copy:\n");
    mv_print(matrix2);

    printf("\nmatrix2 data arr after copy:\n");
    size_t data2_len = sizeof(data2) / sizeof(data2[0]);
    for (size_t i = 0; i < data2_len; ++i)
        printf("%f ", data2[i]);
    printf("\n");

    return EXIT_SUCCESS;
}
