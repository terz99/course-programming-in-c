/*
JTSK-320112
a1 p6.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>

int main(){

    unsigned char ch;
    scanf("%c", &ch);
    getchar();

    printf("The decimal representation is: %d\n", ch);
    printf("The binary representation is: ");

    for(int i = 7; i >= 0; i--){
        printf("%d", ((ch >> i) & 1));
    }
    printf("\n");

    return 0;
}