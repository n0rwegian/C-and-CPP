#include <stdio.h>

int main(void)
{   
    double nums[20] = {};
    double sum = 0;
    char c;
    int i = 0;
    while ((scanf("%lf%c", &nums[i++], &c) == 2) && (c != '\n') && (c != EOF)) { };
    for (int j = 0; j < i; ++j) { sum += nums[j]; }
    
    printf("%.2lf", sum / (double) i);

    return 0;
}