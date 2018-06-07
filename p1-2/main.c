/*
JTSK-320112
a1 p2.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>

#define LEAST_SIGNIFICANT_BIT(A) (A & 1)

int main(){

    unsigned char ch;
    scanf("%c", &ch);
    getchar();

    printf("The decimal representation is: %d\n", ch);
    printf("The least significant bit is: %d\n", LEAST_SIGNIFICANT_BIT(ch));

    return 0;
}