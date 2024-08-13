/*
Подвиг 8. Продолжите программу, которая читает из входного потока строку целиком с помощью функции fgets(). На
выходе формируется корректная Си строка. Выделите из строки второе слово (слова разделяются одним или
несколькими пробелами) и выведите его в консоль. Пробелов до и после выделенного слова быть не должно. Если
строка состоит из одного слова, то в консоль вывести "no".

P. S. Пробелы могут быть в начале и в конце строки.
*/

#include <stdio.h>

void strip_string(char* str, int max_len) {
    int count = 0;
    while (*str++ != '\0' && count++ < max_len)
        ;

    if (count > 0) {
        str -= 2;
        if (*str == '\n') *str = '\0';
    }
}

int main(void) {
    char str[100];
    fgets(str, sizeof(str), stdin);
    strip_string(str, sizeof(str));

    int flag = 1, counter = 0, start = 0, end = 0;
    for (int i = 0;; ++i) {
        if (str[i] != ' ' && str[i] != '\0') {
            if (flag) {
                if (counter == 1) start = i;
                ++counter;
                flag = 0;
            }
        } else {
            flag = 1;
            if (counter == 2) {
                end = i;
                break;
            }
            if (str[i] == '\0') break;
        }
    }

    if (end) {
        char word2[end - start + 1];
        for (int i = start; i < end; ++i) {
            word2[i - start] = str[i];
        }
        word2[end - start] = '\0';
        printf("%s", word2);
    } else {
        printf("no");
    }

    return 0;
}