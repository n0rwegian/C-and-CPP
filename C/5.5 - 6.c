/*
Подвиг 4. Продолжите программу. Необходимо после каждого элемента со значением 5 массива digs вставлять новые
элементы со значениями: -1 - после первой найденной пятерки; -2 - после второй пятерки и т.д. Обратите
внимание, что при вставке новых значений, последние элементы массива digs могут теряться. Также следует
учитывать, что элемент со значением 5 может отсутствовать в массиве digs (тогда ничего вставлять не нужно).
Выведите в консоль по порядку значения всех прочитанных + добавленных элементов массива digs в одну строчку
через пробел.
*/

#include <stdio.h>

#define TOTAL 10

int main(void) {
    int digs[TOTAL] = {0};
    size_t count = 0;
    size_t sz_ar = sizeof(digs) / sizeof(*digs);

    while (count < sz_ar && scanf("%d", &digs[count]) == 1) count++;

    size_t counter = 0;
    for (size_t i = 0; i < count; ++i) {
        if (digs[i] == 5) {
            ++counter;
        }
    }

    count = (count + counter < TOTAL) ? count + counter : TOTAL;

    size_t j = count - 1;
    while (counter > 0) {
        if (digs[j - counter] != 5) {
            digs[j] = digs[j - counter];
            --j;
        } else {
            digs[j] = -counter;
            digs[j - 1] = digs[j - counter];
            --counter;
            --j;
            --j;
        }
    }

    for (size_t i = 0; i < count; ++i) {
        printf("%d ", digs[i]);
    }

    return 0;
}