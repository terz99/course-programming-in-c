/*
JTSK-320112
a1 p1.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>

#define SWAP(A, B, C) { C tmp = A; A = B; B = tmp; }

int main(){

    int a, b;
    scanf("%d%d", &a, &b);
    getchar();
    double c, d;
    scanf("%lf%lf", &c, &d);
    getchar();

    SWAP(a, b, int);
    SWAP(c, d, double);

    printf("After swapping:\n%d\n%d\n%.6lf\n%.6lf\n", a, b, c, d);

    return 0;
}