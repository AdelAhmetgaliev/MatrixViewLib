# MatrixViewLib
## Библиотека для работы с матрицами.
MatrixView --- структура, которая хранит представление линейных данных как матрицу.
Никакой работы с памятью (аллоцирование и деаллоцирование) не происходит.
Вся работа с памятью должна происходить вне структуры.

### Вид структуры MatrixView
```C
typedef struct _MatrixView {
    double *dataView;
    size_t rowCount;
    size_t colCount;
} MatrixView;
```

### Реализованные методы
#### Создание нового экземпляра структуры
```C
MatrixView mv_new(double *dataView, size_t rowCount, size_t colCount);
```
#### Вывод в консоль
```C
void mv_print(const MatrixView *matrix);
```

#### Копирование
Копирует элементы матрицы *src* в матрицу *dest*. Размеры матриц должны быть одинаковы.
```C
void mv_copy(MatrixView *dest, const MatrixView *src);
```

Копирует элементы матрицы *src* в матрицу *dest*. Общие размеры матриц должны быть одинаковы.
```C
void mv_copydf(MatrixView *dest, const MatrixView *src);
```

Различие двух функций копирования в том, что `mv_copy` требует строгого соответсвия размеров
матриц (количества строк и столбцов). В то время как для `mv_copydf` достаточно соответствия
размеров линейных массивов (`dataView[]`).

#### Суммирование
Суммирует матрицы *left* и *right*. Записывает результат в *dest*.
```C
void mv_sum(MatrixView *dest, const MatrixView *left, const MatrixView *right);
```

Суммирует матрицы *dest* и *src*. Записывает результат в *dest*.
```C
void mv_sumto(MatrixView *dest, const MatrixView *src);
```

#### Умножение
Умножает матрицы *left* и *right*. Записывает результат в *dest*.
```C
void mv_dot(MatrixView *dest, const MatrixView *left, const MatrixView *right);
```

Тензорно умножает матрицы *left* и *right*. Записывает результат в *dest*.
```C
void mv_tdot(MatrixView *dest, const MatrixView *left, const MatrixView *right);
```

#### Рандомизация
Заполняет матрицу рандомными значениями от -1.0 до +1.0.
```C
void mv_rand(MatrixView *matrix);
```

#### Применение функции
Применяет функцию *func* ко всем элементам матрицы.
```C
void mv_map(MatrixView *matrix, double (*func)(double));
```

### Макросы
Макрос заменяющий обращение `matrix[row][col]`. 
```C
#define mv_get(matrix, row, col) (matrix).dataView[(row) * (matrix).colCount + (col)]
```
