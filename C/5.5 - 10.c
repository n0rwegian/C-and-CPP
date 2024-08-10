/*
Подвиг 8. Продолжите программу. Выполните сортировку второй половины массива ws по убыванию (невозрастанию),
используя метод сортировки выбором. То есть, сортировать нужно элементы с индексами от count/2 до count-1
включительно. Выведите в консоль все полученные значения массива ws (первые count элементов) в одну строчку
через пробел с точностью до сотых.
*/

/* Selection sort */
#include <stdio.h>

#define TOTAL 20

int main(void) {
    float ws[TOTAL] = {0.0f};
    size_t count = 0;
    size_t sz_ar = sizeof(ws) / sizeof(*ws);

    while (count < sz_ar && scanf("%f", &ws[count]) == 1) count++;

    float tmp;
    for (size_t i = count / 2; i < count; ++i) {
        float max = ws[i];
        size_t max_index = i;
        for (size_t j = i; j < count; ++j) {
            if (ws[j] > max) {
                max_index = j;
                max = ws[j];
            }
        }
        tmp = ws[i];
        ws[i] = ws[max_index];
        ws[max_index] = tmp;
    }

    for (size_t i = 0; i < count; ++i) {
        printf("%.2f ", ws[i]);
    }

    return 0;
}