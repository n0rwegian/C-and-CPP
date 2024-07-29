/*
Подвиг 8. Продолжите программу. Прочитайте из входного потока целые числа в переменные var_1, var_2 и var_3,
записанные в одну строчку через запятую. Побайтно занесите их значения в массив типа char (в порядке var_1,
var_2, var_3). Выведите в одну строчку через пробел по порядку значения массива в виде беззнаковых десятичных
чисел.
*/

#include <stdio.h>

int main(void)
{
    short var_1;
    int var_2;
    long long var_3;

    scanf("%hd,%d,%lld", &var_1, &var_2, &var_3);

    int len_1 = sizeof(var_1), len_2 = sizeof(var_2), len_3 = sizeof(var_3);
    
    unsigned char num[len_1 + len_2 + len_3];
    
    int i = 0;
    char *ptr_var = (char *)&var_1;
    for (; i < len_1; ++i) { *(num + i) = *(ptr_var + i); }  
    ptr_var = (char *)&var_2;
    for (; i < len_1 + len_2; ++i) { *(num + i) = *(ptr_var + i - len_1); }  
    ptr_var = (char *)&var_3;
    for (; i < len_1 + len_2 + len_3; ++i) { *(num + i) = *(ptr_var + i - len_1 - len_2); }  
    for (int j = 0; j < len_1 + len_2 + len_3; ++j) { printf("%hhu ", num[j]); }

    return 0;
}