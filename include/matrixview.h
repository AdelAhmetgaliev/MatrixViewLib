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

/**
 * Создает новый экземпляр структуры MatrixView.
 * @param *dataView поинтер на линейный массив.
 * @param rowCount кол-во строк в представлении.
 * @param colCount кол-во столбцов в представлении.
 */
MatrixView mv_new(double *dataView, size_t rowCount, size_t colCount);

/**
 * Выводит экземпляр структуры MatrixView в stdout.
 * @param *matrix поинтер на экземпляр структуры.
 */
void mv_print(const MatrixView *matrix);

/**
 * Копирует элементы одной MatrixView в другую.
 * Размеры (число строк и число столбцов) должны быть одинаковы.
 * @param *dest поинтер на MatrixView куда идет копирование.
 * @param *src поинтер на MatrixView откуда идет копирование.
 */
void mv_copy(MatrixView *dest, const MatrixView *src);

/**
 * Копирует элементы одной MatrixView в другую.
 * Общие размеры (размеры линейных массивов) должны быть одинаковы.
 * @param *dest поинтер на MatrixView куда идет копирование.
 * @param *src поинтер на MatrixView откуда идет копирование.
 */
void mv_copydf(MatrixView *dest, const MatrixView *src);

/**
 * Суммирует элементы двух MatrixView.
 * @param *dest поинтер на MatrixView куда будут суммироваться элементы.
 * @param *left поинтер на MatrixView первого слагаемого.
 * @param *right поинтер на MatrixView второго слагаемого.
 */
void mv_sum(MatrixView *dest, const MatrixView *left, const MatrixView *right);

/**
 * Суммирует элементы двух MatrixView. Результат помещает в первое слагаемое.
 * @param *dest поинтер на MatrixView первого слагаемого.
 * @param *src поинтер на MatrixView второго слагаемого.
 */
void mv_sumto(MatrixView *dest, const MatrixView *src);

/**
 * Матрично умножает две MatrixView.
 * @param *dest поинтер на MatrixView куда будет записано произведение.
 * @param *left поинтер на MatrixView первого множителя.
 * @param *right поинтер на MatrixView второго множителя.
 */
void mv_dot(MatrixView *dest, const MatrixView *left, const MatrixView *right);

/**
 * Тензорно умножает две MatrixView.
 * @param *dest поинтер на MatrixView куда будет записано произведение.
 * @param *left поинтер на MatrixView первого множителя.
 * @param *right поинтер на MatrixView второго множителя.
 */
void mv_tdot(MatrixView *dest, const MatrixView *left, const MatrixView *right);

/**
 * Заполняет MatrixView случайными числами от -1.0 до 1.0.
 * @param *matrix поинтер на MatrixView.
 */
void mv_rand(MatrixView *matrix);

/**
 * Применяет функцию ко всем элементам MatrixView.
 * @param *matrix поинтер на MatrixView.
 * @param *func поинтер на функцию.
 */
void mv_map(MatrixView *matrix, double (*func)(double));

/* Макрос ссылающийся на данные в ячейке matrix[row][col]. */
#define mv_get(matrix, row, col) (matrix).dataView[(row) * (matrix).colCount + (col)]

#endif /* MATRIXVIEW_H_ */
