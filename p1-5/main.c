/*
JTSK-320112
a1 p5.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>

int main(){

    unsigned char ch;
    scanf("%c", &ch);
    getchar();

    printf("The decimal representation is: %d\n", ch);
    printf("The backwards binary representation is: ");
    
    // the next two lines calculate how many bits does the number have
    // REMEMBER THIS: 1 << bit_size means 2^bit_size, or in plain English two to the power of bit_size
    // Think of an example. Say the character '2'. The character '2' has ASCII code of '2' is 50
    // dont mix (2 and '2', the first is a plain number/integer and the other one is a character represented with a plain number/integer 50)
    // using 8 bits we can represent 50 as 00110010 in binary. However the two zeros on the left side are not needed.
    // basically 00110010 is the same as 110010, the same way as 2.5600000 is the same as 2.56, get it?
    // so the next two lines basically calculate how many bits does the character need, in this case 6 (110010)
    // How do we find that? we iterate 2^bit_size until 2^bit_size is >= ch. See that 2^6=64 is bigger than 50, thus log2(2^6) = 6 WHICH IS THE NUMBER OF BITS NEEDED
    int bit_size;
    for(bit_size = 0; (1 << bit_size) <= ch; bit_size++);

    for(int i = 0; i < bit_size; i++){
        // in this loop i just shift the bits to the right for 'i' positions. Consider the previous example of 110010
        // 1st iteration: 110010 >> 0 = 110010, then 110010 & 1 (which is basically 000001 in binary), we get 0
        // 2nd iteration: 110010 >> 1 = 011001 & 000001 = 1
        // and so on... at the end you get the binary representation backwards... i hope you get this HAHAHH
        printf("%d", ((ch >> i) & 1));
    }
    printf("\n");

    return 0;
}
