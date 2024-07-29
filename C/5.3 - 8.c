#include <stdio.h>

int main(void)
{
    int nums[10] = {};
    int tmp;
    char c;
    int i = 0;
    while ((scanf("%d%c", &tmp, &c) == 2) && (i < 10) && (c != '\n') && (c != EOF)) {
        nums[i] = tmp;
        ++i;
    }

    int j = 0;
    while (nums[j] > 0 && nums[j] % 2 && j < i) { ++j; }
    printf("%d", (i == j));

    return 0;
}