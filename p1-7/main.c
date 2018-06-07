/*
JTSK-320112
a1 p7.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>

void set3bits(unsigned char *ch, int pos1, int pos2, int pos3){

    /*
    This function sets the positions pos1, pos2, and pos3
    of binary representation of ch into 1s
    */

    // in order to turn on a bit in a bitmask, you need to do an OR operation on it
    // 1 << pos is basically 2^pos, which actually gives us the position of some bit
    // just do examples, you'll get it
    *ch |= (1 << pos1);
    *ch |= (1 << pos2);
    *ch |= (1 << pos3);
}

int main(){

    unsigned char ch;
    int pos1, pos2, pos3;
    scanf("%c%d%d%d", &ch, &pos1, &pos2, &pos3);
    getchar();

    printf("The decimal representation is: %d\n", ch);
    printf("The binary representation is: ");
    for(int i = 7; i >= 0; i--){
        // Here i do the same as p1.5, but instead of starting at 0 i start at 7, so i get the bits in a regular order (not backwards)
        printf("%d", ((ch >> i) & 1));
    }
    set3bits(&ch, pos1, pos2, pos3);
    printf("\nAfter setting the bits: ");
    for(int i = 7; i >= 0; i--){
        // same as up
        printf("%d", ((ch >> i) & 1));
    }
    printf("\n");

    return 0;
}