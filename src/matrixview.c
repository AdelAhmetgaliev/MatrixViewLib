#include "matrixview.h"

#include <assert.h>
#include <stdio.h>

MatrixView mv_new(double *dataView, size_t rowCount, size_t colCount) {
    return (MatrixView) { .dataView = dataView, .rowCount = rowCount, .colCount = colCount };
}

void mv_print(const MatrixView *matrix) {
    for (size_t i = 0; i < matrix->rowCount; ++i) {
        for (size_t j = 0; j < matrix->colCount; ++j)
            printf("%f ", mv_get(*matrix, i, j));
        printf("\n");
    }
}

void mv_copy(MatrixView *dest, const MatrixView *src) {
    assert(dest->rowCount == src->rowCount && "Ошибка! Неравное число строк!");
    assert(dest->colCount == src->colCount && "Ошибка! Неравное число столбцов!");

    for (size_t i = 0; i < dest->rowCount; ++i)
        for (size_t j = 0; j < dest->colCount; ++j)
            mv_get(*dest, i, j) = mv_get(*src, i, j);
}

void mv_copydf(MatrixView *dest, const MatrixView *src) {
    assert(dest->rowCount * dest->colCount == src->rowCount * src->colCount &&
            "Ошибка! Общие размеры матриц различны!");

    for (size_t i = 0; i < dest->rowCount * dest->colCount; ++i)
        dest->dataView[i] = src->dataView[i];
}

void mv_sum(MatrixView *dest, const MatrixView *left, const MatrixView *right) {
    assert(left->rowCount == right->rowCount &&
            "Ошибка! Число строк двух слагаемых различается!");
    assert(left->colCount == right->colCount &&
            "Ошибка! Число столбцов двух слагаемых различается!");
    assert(dest->rowCount == left->rowCount &&
            "Ошибка! Число строк матрицы-суммы отлично от матриц-слагаемых!");
    assert(dest->colCount == left->colCount &&
            "Ошибка! Число столбцов матрицы-суммы отлично от матриц-слагаемых!");

    for (size_t i = 0; i < dest->rowCount; ++i)
        for (size_t j = 0; j < dest->colCount; ++j)
            mv_get(*dest, i, j) = mv_get(*left, i, j) + mv_get(*right, i, j);
}

void mv_sumto(MatrixView *dest, const MatrixView *src) {
    assert(dest->rowCount == src->rowCount && "Ошибка! Число строк у двух матриц различается!");
    assert(dest->colCount == src->colCount && "Ошибка! Число столбцов у двух матриц различается!");

    for (size_t i = 0; i < dest->rowCount; ++i)
        for (size_t j = 0; j < dest->colCount; ++j)
            mv_get(*dest, i, j) += mv_get(*src, i, j);
}

void mv_dot(MatrixView *dest, const MatrixView *left, const MatrixView *right) {
    assert(left->colCount == right->rowCount &&
            "Ошибка! Число столбцов левого множителя не равно числу строк правого!");
    assert(dest->rowCount == left->rowCount && dest->colCount == right->colCount &&
            "Ошибка! Матрица-произведение не соответствует размерам!");

    for (size_t i = 0; i < dest->rowCount; ++i) {
        for (size_t j = 0; j < dest->colCount; ++j) {
            mv_get(*dest, i, j) = 0.0;
            for (size_t k = 0; k < left->colCount; ++k)
                mv_get(*dest, i, j) += mv_get(*left, i, k) * mv_get(*right, k, j);
        }
    }
}

void mv_tdot(MatrixView *dest, const MatrixView *left, const MatrixView *right) {
    (void) dest;
    (void) left;
    (void) right;

    assert(0 && "Not implemented!");
}

static double randd(void) {
    return ((double) rand() / RAND_MAX) * 2.0 - 1.0;
}

void mv_rand(MatrixView *matrix) {
    for (size_t i = 0; i < matrix->rowCount * matrix->colCount; ++i) {
        matrix->dataView[i] = randd();
    }
}

void mv_map(MatrixView *matrix, double (*func)(double)) {
    for (size_t i = 0; i < matrix->rowCount * matrix->colCount; ++i) {
        matrix->dataView[i] = func(matrix->dataView[i]);
    }
}
