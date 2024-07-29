#include <stdio.h>

int main(void)
{
    int value;
    scanf("%d", &value);
    char ar_d[4];
    char *value_ptr = (char *)&value;
    int i = 0;
    while (value_ptr < (char *)(&value + 1)) { 
        *(ar_d + i) = *value_ptr;
        ++i;
        ++value_ptr;
    }
    
    for (int i = 0; i < 4; ++i) { printf("%d ", ar_d[i]); }
    
    return 0;
}