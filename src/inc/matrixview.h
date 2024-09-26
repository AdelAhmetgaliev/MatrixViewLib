/**
 * MatrixView --- структура, которая хранит представление линейных данных как матрицу.
 * Никакой работы с памятью (аллоцирование и деаллоцирование) не происходит.
 * Вся работа с памятью должна просиходить вне структуры.
 */ 

#ifndef MATRIXVIEW_H_
#define MATRIXVIEW_H_

#include <stdlib.h>

/* Макрос ссылающийся на данные в ячейке matrix[row][col]. */
#define MV_GET(matrix, row, col) (matrix).dataView[(row) * (matrix).colCount + (col)]

typedef struct _MatrixView {
    double *dataView;   /* Поинтер на линейный массив. */
    size_t rowCount;    /* Кол-во строк в представлении. */
    size_t colCount;    /* Кол-во столбцов в представлении. */
} MatrixView;

MatrixView mv_new(double *dataView, size_t rowCount, size_t colCount);
void mv_print(MatrixView matrix);
void mv_copy(MatrixView dest, MatrixView src);
void mv_sum(MatrixView dest, MatrixView left, MatrixView right);
void mv_sumto(MatrixView dest, MatrixView src);
void mv_dot(MatrixView dest, MatrixView left, MatrixView right);

#endif /* MATRIXVIEW_H_ */
