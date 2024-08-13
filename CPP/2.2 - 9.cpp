/*
Подвиг 7. Объявите класс с именем IntOperator, содержащий следующие элементы:

- приватные переменные:

int* data {nullptr}; // массив целочисленных значений
int size {0}; // длина массива (число элементов)
- публичные методы:

double average(); // вычисление среднего арифметического по массиву data
int sum(); // вычисление суммы значений массива data
int max(); // нахождение максимального значения в массиве data
int min(); // нахождение минимального значения в массиве data
В классе IntOperator объявить конструктор(ы), чтобы его объекты можно было создавать командами:

int dt[] = {0, -5, 2, 10, 7, 22};

IntOperator op_1;
IntOperator op2(dt, std::size(dt)); // std::size() возвращает число элементов массива data (C++17)
Объявите в классе IntOperator деструктор, чтобы при удалении объекта значения переданного массива (в примере
dt) были равны нулю.

P.S. В программе требуется только объявить класс IntOperator. На экран ничего выводить не нужно.
*/

#include <iostream>

class IntOperator {
    int* data{nullptr};  // массив целочисленных значений
    int size{0};         // длина массива (число элементов)
   public:
    IntOperator() {}
    IntOperator(int* init_data, int init_size) : data(init_data), size(init_size) {}
    int sum() {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
        return sum;
    }
    double average() { 
        if (size == 0) return 0.0;
        return (double)this->sum() / (double)size; 
        }
    int max() {
        if (size == 0) return 0;
        int max_el = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] > max_el) {
                max_el = data[i];
            }
        }
        return max_el;
    }
    int min() {
        if (size == 0) return 0;
        int min_el = data[0];
        for (int i = 1; i < size; ++i) {
            if (data[i] < min_el) {
                min_el = data[i];
            }
        }
        return min_el;
    }
    ~IntOperator() { 
        for (int i = 0; i < size; ++i) data[i] = 0;
        //delete[] data; 
    }
};

int main() {
    int dt[] = {0, -5, 2, 10, 7, 22};

    IntOperator op_1;
    IntOperator op2(dt, std::size(dt));  // std::size() возвращает число элементов массива data (C++17)

    printf("%d %d %.2lf %d\n", op_1.min(), op_1.max(), op_1.average(), op_1.sum());
    printf("%d %d %.2lf %d\n", op2.min(), op2.max(), op2.average(), op2.sum());

    return 0;
}