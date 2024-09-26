#include "matrixview.h"

#include <assert.h>
#include <stdio.h>

MatrixView mv_new(double *dataView, size_t rowCount, size_t colCount) {
    return (MatrixView) {.dataView = dataView, .rowCount = rowCount, .colCount = colCount};
}

void mv_print(MatrixView matrix) {
    for (size_t i = 0; i < matrix.rowCount; ++i) {
        for (size_t j = 0; j < matrix.colCount; ++j)
            printf("%f ", MV_GET(matrix, i, j));
        printf("\n");
    }
}

void mv_copy(MatrixView dest, MatrixView src) {
    assert(dest.rowCount == src.rowCount && "Ошибка! Неравное число строк!\n");
    assert(dest.colCount == src.colCount && "Ошибка! Неравное число столбцов!\n");

    for (size_t i = 0; i < dest.rowCount; ++i)
        for (size_t j = 0; j < dest.colCount; ++j)
            MV_GET(dest, i, j) = MV_GET(src, i, j);
}

void mv_sum(MatrixView dest, MatrixView left, MatrixView right) {
    assert(left.rowCount == right.rowCount &&
            "Ошибка! Число строк двух слагаемых различается!\n");
    assert(left.colCount == right.colCount &&
            "Ошибка! Число столбцов двух слагаемых различается!\n");
    assert(dest.rowCount == left.rowCount &&
            "Ошибка! Число строк матрицы-суммы отлично от матриц-слагаемых!\n");
    assert(dest.colCount == left.colCount &&
            "Ошибка! Число столбцов матрицы-суммы отлично от матриц-слагаемых!\n");

    for (size_t i = 0; i < dest.rowCount; ++i)
        for (size_t j = 0; j < dest.colCount; ++j)
            MV_GET(dest, i, j) = MV_GET(left, i, j) + MV_GET(right, i, j);
}

void mv_sumto(MatrixView dest, MatrixView src) {
    assert(dest.rowCount == src.rowCount && "Ошибка! Число строк у двух матриц различается!\n");
    assert(dest.colCount == src.colCount && "Ошибка! Число столбцов у двух матриц различается!\n");

    for (size_t i = 0; i < dest.rowCount; ++i)
        for (size_t j = 0; j < dest.colCount; ++j)
            MV_GET(dest, i, j) += MV_GET(src, i, j);
}
