/*
Подвиг 7. Продолжите программу. Выполните сортировку массива ws по возрастанию (неубыванию), используя метод
сортировки выбором. Сортировать нужно только первые count элементов. Выведите в консоль значения
отсортированного массива ws (первые count элементов) в одну строчку через пробел с точностью до сотых.
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
    for (size_t i = 0; i < count; ++i) {
        float min = ws[i];
        size_t min_index = i;
        for (size_t j = i; j < count; ++j) {
            if (ws[j] < min) {
                min_index = j;
                min = ws[j];
            }
        }
        tmp = ws[i];
        ws[i] = ws[min_index];
        ws[min_index] = tmp;
    }

    for (size_t i = 0; i < count; ++i) {
        printf("%.2f ", ws[i]);
    }

    return 0;
}