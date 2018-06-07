/*
JTSK-320112
a1 p3.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>

#define MAX(X, Y, Z) ((X > Y) ? ((X > Z) ? X : Z) : ((Y > Z) ? Y : Z))
#define MIN(X, Y, Z) ((X < Y) ? ((X < Z) ? X : Z) : ((Y < Z) ? Y : Z))
#define MID_RANGE(X, Y, Z) ((MAX(X, Y, Z)+MIN(X, Y, Z))/2.0)

int main(){

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    getchar();

    printf("The mid-range is: %lf\n", MID_RANGE((double)a, (double)b, (double)c));

    return 0;
}