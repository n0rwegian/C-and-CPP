/*
Подвиг 6. Продолжите программу. Из массива pows необходимо удалить все элементы кратные 3 (делятся нацело на
3). Если таких элементов нет, то ничего удалять не нужно. Выведите в консоль по порядку в одну строчку через
пробел полученные значения оставшихся элементов массива pows.
*/

#include <stdio.h>

#define TOTAL 20

int main(void) {
    short pows[TOTAL] = {0};
    size_t count = 0;
    size_t sz_ar = sizeof(pows) / sizeof(*pows);

    while (count < sz_ar && scanf("%hd", &pows[count]) == 1) count++;

    size_t l = 0;
    for (size_t r = 0; r < count; ++r) {
        if (pows[r] % 3 != 0) {
            pows[l] = pows[r];
            ++l;
        }
    }

    count = l;

    for (size_t i = 0; i < count; ++i) {
        printf("%d ", pows[i]);
    }

    return 0;
}