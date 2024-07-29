/*
Подвиг 9. Продолжите программу, в которой уже объявлена структура Point. Объявите после нее класс с именем PolyLine, содержащий следующие элементы:

- приватные поля:

enum { max_coords = 10 };
Point coords[max_coords]; // координаты точек полилинии
int total {0};            // количество точек полилинии
- публичные методы:

void set_coords(const Point* ar, int size); // передача массива координат размером size элементов
void append_coord(Point pt); // добавление в конец массива coords переданной координаты pt
const Point* get_coords(); // получение списка координат
int get_total(); // получение значения поля total
При реализации методов set_coords и append_coord необходимо проверять выход за пределы массива coords. Контролировать, чтобы сохранялись только первые max_coords элементы переданных данных, если количество координат превышает значение max_coords.

В классе Line объявите конструктор(ы) так, чтобы объекты можно было создавать командами:

PolyLine poly_1; // без координат (total = 0)
PolyLine poly_2(ar, size_ar); // с координатами ar количеством size_ar (элементы массива ar имеют тип Point)
В функции main создайте два объекта класса PolyLine в виде обычных переменных с именами poly и pl. Первый объект poly с координатами coords в количестве 20 элементов (coords уже создан в функции main). Второй объект без координат. Вызовите для второго объекта метод append_coord и передайте ему последнюю координату из массива coords.

P.S. На экран ничего выводить не нужно.
*/

#include <iostream>

struct Point
{
    short x, y;
};

class PolyLine {
    enum { max_coords = 10 };
    Point coords[max_coords]; // координаты точек полилинии
    int total {0};            // количество точек полилинии
public:
    PolyLine(int t = 0): total(t) {};
    PolyLine(Point ar[], int size_ar) {
        total = (size_ar < max_coords) ? size_ar : max_coords;
        for (int i = 0; i < total; ++i) {
            coords[i] = ar[i];
        };
    };
    void set_coords(const Point* ar, int size) {
        total = (size < max_coords) ? size : max_coords;
        for (int i = 0; i < total; ++i) {
            coords[i] = ar[i];
        };
    }; // передача массива координат размером size элементов
    void append_coord(Point pt) {
        if (total < max_coords) { 
            coords[total] = pt;
            ++total;
        }
    }; // добавление в конец массива coords переданной координаты pt
    const Point* get_coords() { return this->coords; }; // получение списка координат
    int get_total() { return this->total; }; // получение значения поля total
};

int main(void)
{
    Point coords[20];
    for(int i = 0;i < 20; ++i) {
        coords[i].x = i+1;
        coords[i].y = i+2;
    }

    PolyLine poly(coords, 20), pl;
    pl.append_coord(coords[19]);
    // printf("%d\n", poly.get_total());
    // printf("%d\n", pl.get_total());

    // __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0 или перед освобождением памяти)

    return 0;
}