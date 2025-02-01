/**
 * MatrixView --- структура, которая хранит представление линейных данных как матрицу.
 * Никакой работы с памятью (аллоцирование и деаллоцирование) не происходит.
 * Вся работа с памятью должна происходить вне структуры.
 */

#ifndef MATRIXVIEW_H_
#define MATRIXVIEW_H_

#include <stdlib.h>

typedef struct _MatrixView {
    double *dataView;   /* Поинтер на линейный массив. */
    size_t rowCount;    /* Кол-во строк в представлении. */
    size_t colCount;    /* Кол-во столбцов в представлении. */
} MatrixView;

MatrixView mv_new(double *dataView, size_t rowCount, size_t colCount);
void mv_print(const MatrixView *matrix);
void mv_copy(MatrixView *dest, const MatrixView *src);
void mv_copydf(MatrixView *dest, const MatrixView *src);
void mv_sum(MatrixView *dest, const MatrixView *left, const MatrixView *right);
void mv_sumto(MatrixView *dest, const MatrixView *src);
void mv_dot(MatrixView *dest, const MatrixView *left, const MatrixView *right);
void mv_tdot(MatrixView *dest, const MatrixView *left, const MatrixView *right);
void mv_rand(MatrixView *matrix);
void mv_map(MatrixView *matrix, double (*func)(double));

/* Макрос ссылающийся на данные в ячейке matrix[row][col]. */
#define mv_get(matrix, row, col) (matrix).dataView[(row) * (matrix).colCount + (col)]

#endif /* MATRIXVIEW_H_ */
