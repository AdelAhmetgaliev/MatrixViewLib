/**
 * MatrixView --- структура, которая хранит представление линейных данных как матрицу.
 * Никакой работы с памятью (аллоцирование и деаллоцирование) не происходит.
 * Вся работа с памятью должна происходить вне структуры.
 */

#ifndef MATRIXVIEW_H_
#define MATRIXVIEW_H_

#include <stdlib.h>

typedef struct _MatrixView {
    double *dataView; /* Указатель на линейный массив. */
    size_t rowCount;  /* Кол-во строк в представлении. */
    size_t colCount;  /* Кол-во столбцов в представлении. */
} MatrixView;

/**
 * Создает новый экземпляр структуры MatrixView.
 * @param *dataView указатель на линейный массив.
 * @param rowCount кол-во строк в представлении.
 * @param colCount кол-во столбцов в представлении.
 */
MatrixView mv_new(double *dataView, size_t rowCount, size_t colCount);

/**
 * Выводит экземпляр структуры MatrixView в stdout.
 * @param *matrix указатель на экземпляр структуры.
 */
void mv_print(const MatrixView *matrix);

/**
 * Копирует элементы одной MatrixView в другую.
 * Размеры (число строк и число столбцов) должны быть одинаковы.
 * @param *dest указатель на MatrixView куда идет копирование.
 * @param *src указатель на MatrixView откуда идет копирование.
 */
void mv_copy(MatrixView *dest, const MatrixView *src);

/**
 * Копирует элементы одной MatrixView в другую.
 * Общие размеры (размеры линейных массивов) должны быть одинаковы.
 * @param *dest указатель на MatrixView куда идет копирование.
 * @param *src указатель на MatrixView откуда идет копирование.
 */
void mv_copy_raw(MatrixView *dest, const MatrixView *src);

/**
 * Транспонирует MatrixView.
 * @param *dest указатель на MatrixView транспонированной матрицы.
 * @param *src указатель на MatrixView исходной матрицы.
 */
void mv_transpose(MatrixView *dest, const MatrixView *src);

/**
 * Суммирует элементы двух MatrixView.
 * @param *dest указатель на MatrixView куда будут суммироваться элементы.
 * @param *left указатель на MatrixView первого слагаемого.
 * @param *right указатель на MatrixView второго слагаемого.
 */
void mv_sum(MatrixView *dest, const MatrixView *left, const MatrixView *right);

/**
 * Суммирует элементы двух MatrixView. Результат помещает в первое слагаемое.
 * @param *dest указатель на MatrixView первого слагаемого.
 * @param *src указатель на MatrixView второго слагаемого.
 */
void mv_sumto(MatrixView *dest, const MatrixView *src);

/**
 * Умножает MatrixView на double.
 * @param *matrix указатель на MatrixView.
 * @param scalar число для умножения.
 */
void mv_scale(MatrixView *matrix, double scalar);

/**
 * Матрично умножает две MatrixView.
 * @param *dest указатель на MatrixView куда будет записано произведение.
 * @param *left указатель на MatrixView первого множителя.
 * @param *right указатель на MatrixView второго множителя.
 */
void mv_dot(MatrixView *dest, const MatrixView *left, const MatrixView *right);

/**
 * Тензорно умножает две MatrixView.
 * @param *dest указатель на MatrixView куда будет записано произведение.
 * @param *left указатель на MatrixView первого множителя.
 * @param *right указатель на MatrixView второго множителя.
 */
void mv_tdot(MatrixView *dest, const MatrixView *left, const MatrixView *right);

/**
 * Заполняет MatrixView случайными числами от -1.0 до 1.0.
 * @param *matrix указатель на MatrixView.
 */
void mv_rand(MatrixView *matrix);

/**
 * Применяет функцию ко всем элементам MatrixView.
 * @param *matrix указатель на MatrixView.
 * @param *func указатель на функцию.
 */
void mv_map(MatrixView *matrix, double (*func)(double));

/* Макрос ссылающийся на данные в ячейке matrix[row][col]. */
#define mv_get(matrix, row, col) (matrix).dataView[(row) * (matrix).colCount + (col)]

#endif /* MATRIXVIEW_H_ */
