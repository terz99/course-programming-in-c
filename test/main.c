#include <stdio.h>

int main(){

    int a = 4;
    int *ptr = &a;
    *ptr = 3;
    printf("%d\n", a);

    a = 50;
    printf("%d\n", *ptr);

    return 0;
}