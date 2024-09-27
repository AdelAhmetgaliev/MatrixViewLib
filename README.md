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
void mv_print(MatrixView matrix);
```
