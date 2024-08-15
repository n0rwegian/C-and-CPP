/*
Подвиг 8. Объявите класс с именем VectorN, содержащий следующие элементы:

- приватные переменные:

int dims {0}; // размерность вектора (число координат)
short* coords {nullptr}; // массив с координатами
- публичные методы:

const short* get_coords(); // возвращает координаты (массив coords)
int get_dims(); // возвращает значение поля dims
В классе VectorN объявить конструктор(ы) так, чтобы его объекты можно было создавать командами:

short data[] = {4, 2, 10, 0, -5};
VectorN v1 = 5; // формирование вектора с пятью нулевыми координатами: 0 0 0 0 0
VectorN v2(1, 2); // формирование вектора с двумя координатами: 1 2
VectorN v3(data, std::size(data)); // формирование вектора с переданными координатами data
При удалении объекта нужно освободить память, занимаемую массивом coords, и вывести в консоль сообщение (без
кавычек и переносом на новую строку):

"delete coords: <координаты через пробел>"

В конце строки пробела быть не должно. Если coords равен nullptr, то ничего выводить не нужно. Например, при
coords = {4, 2, 10, 0, -5}, должно быть выведено:

"delete coords: 4 2 10 0 -5"

P.S. В программе требуется только объявить класс VectorN.
*/

#include <iostream>

class VectorN {
   private:
    int dims{0};             // размерность вектора (число координат)
    short* coords{nullptr};  // массив с координатами
   public:
    VectorN(short* init_coords, int init_dims) {
        dims = init_dims;
        coords = new short[init_dims]{0};
        for (int i = 0; i < init_dims; ++i) {
            coords[i] = init_coords[i];
        }
    }
    VectorN(int init_dims) : dims(init_dims) { coords = new short[init_dims]{0}; }
    VectorN(short dim1, short dim2) : dims(2) { coords = new short[dims]{dim1, dim2}; }
    ~VectorN() {
        if (coords) {
            printf("delete coords: ");
            for (int i = 0; i < dims; ++i) {
                (i == dims - 1) ? printf("%hd\n", coords[i]) : printf("%hd ", coords[i]);
            }
            delete[] coords;
        }
    }
    /*
     ~VectorN() {
         std::cout << "delete coords:";
         for (short* p = coords; p != coords + dims; ++p)
             std::cout << ' ' << *p;
         std::cout << std::endl;
         delete[] coords;
     }
     */
    const short* get_coords() { return coords; };  // возвращает координаты (массив coords)
    int get_dims() { return dims; };               // возвращает значение поля dims
};

int main() {
    short data[] = {4, 2, 10, 0, -5};
    VectorN v1 = 5;  // формирование вектора с пятью нулевыми координатами: 0 0 0 0 0
    VectorN v2(1, 2);  // формирование вектора с двумя координатами: 1 2
    VectorN v3(data, std::size(data));  // формирование вектора с переданными координатами data

    const short* data1 = v3.get_coords();

    // printf("%d %d %d\n", v1.get_dims(), v2.get_dims(), v3.get_dims());
    /*
    for (int i = 0; i < v3.get_dims(); ++i) {
        printf("%hd ", data1[i]);
    }
    */

    return 0;
}