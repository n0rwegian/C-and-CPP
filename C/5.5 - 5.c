/*
Подвиг 3. Продолжите программу. Необходимо после первого найденного элемента со значением 5 массива digs
вставить новое значение -5. Обратите внимание, что при вставке нового значения, последний элемент массива digs
может теряться (если длина массива не позволяет хранить все значения). Также следует учитывать, что элемент со
значением 5 может отсутствовать в массиве digs (тогда ничего вставлять не нужно). Выведите в консоль по
порядку значения всех прочитанных + добавленных элементов массива digs в одну строчку через пробел.
*/

#include <stdio.h>

#define TOTAL 10

int main(void) {
    int digs[TOTAL] = {0};
    size_t count = 0;
    size_t sz_ar = sizeof(digs) / sizeof(*digs);

    while (count < sz_ar && scanf("%d", &digs[count]) == 1) count++;

    size_t i = 0;
    while (i < count) {
        if (digs[i++] == 5) break;
    }
    if (i < count) {
        if (count < TOTAL) ++count;
        for (size_t j = count - 1; j > i; --j) {
            digs[j] = digs[j - 1];
        }
        digs[i] = -5;
    }

    for (size_t j = 0; j < count; ++j) {
        printf("%d ", digs[j]);
    }

    return 0;
}