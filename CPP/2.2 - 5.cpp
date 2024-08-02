/*
Подвиг 3. Продолжите программу, в которой объявлен класс Point:

class Point {
    int x, y;
public:
    int get_x() { return x; }
    int get_y() { return y; }
};
Добавьте в этот класс конструктор(ы) так, чтобы были возможны следующие команды:

Point p1 = "10 5"; // x=10, y=5
Point p2 = "-8.7 2.3"; // x=-8, y=2
Point p3 = "14.2 -5.8 point data"; // x=14, y=-5
То есть, из строки выбираются первые два значения, записанные через пробел(ы) и приводятся к типу int. Если данные оказываются не числовыми, то подставлять значение 0. Например:

Point p_1 = "ab8 2.3"; // x=0, y=2
Point p_2 = "ab8 2cd"; // x=0, y=2 (cd отбрасывается)
Подсказка: для преобразования строк в числа можно использовать функции atoi, atof и другие.

P.S. В программе требуется только объявить класс Point, функцию main не прописывать. На экран ничего выводить не нужно.
*/

#include <iostream>

#define MAX_LEN 10

class Point {
    int x, y;
public:
    Point(const char *string) {
        char x_str[10], y_str[10];
        int i = 0;
        while ((string[i] != ' ') && (i < MAX_LEN)) {
            x_str[i] = string[i];
            ++i;            
        }
        ++i;
        x_str[i] = '\0';
        int j = 0;
        while ((string[i + j] != '\0') && (j < MAX_LEN)) {
            y_str[j] = string[i + j];            
            ++j;
        }
        ++j;
        y_str[j] = '\0';
        this->x = atoi(x_str);
        this->y = atoi(y_str);
    }
    int get_x() { return x; }
    int get_y() { return y; }
};

int main(void)
{
    Point p1 = "10 5"; // x=10, y=5
    Point p2 = "-8.7 2.3"; // x=-8, y=2
    Point p3 = "14.2 -5.8 point data"; // x=14, y=-5
    Point p4 = "-5.5  -0.78 abc\""; // x=14, y=-5
    printf("%d\n", p4.get_x());
    printf("%d\n", p4.get_y());

    return 0;
}