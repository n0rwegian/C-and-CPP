/*
Подвиг 5. Продолжите программу. Из массива pows необходимо удалить элемент с первым найденным четным
значением. Если такой элемент не был найден, то, соответственно, ничего удалять не нужно. Выведите в консоль
по порядку в одну строчку через пробел полученные значения оставшихся элементов массива pows.
*/

#include <stdio.h>

#define TOTAL 20

int main(void) {
    short pows[TOTAL] = {0};
    size_t count = 0;
    size_t sz_ar = sizeof(pows) / sizeof(*pows);

    while (count < sz_ar && scanf("%hd", &pows[count]) == 1) count++;

    for (size_t i = 0; i < count; ++i) {
        if (pows[i] % 2 == 0) {
            for (size_t j = i; j < count - 1; ++j) {
                pows[j] = pows[j + 1];
            }
            count -= 1;
            break;
        }
    }

    for (size_t i = 0; i < count; ++i) {
        printf("%d ", pows[i]);
    }

    return 0;
}