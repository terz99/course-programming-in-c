/*
JTSK-320112
a2 p2.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char one[100], two[100];

    fgets(one, sizeof(one), stdin);
    fgets(two, sizeof(two), stdin);
    one[strlen(one)-1] = '\0';
    two[strlen(two)-1] = '\0';

    char *concat;
    concat = (char*)malloc((strlen(one)+strlen(two))*sizeof(char));
    if(concat == NULL){
        // bad alloc
        exit(1);
    }

    char *concat_ptr = concat;
    for(char *ptr = one; ptr < one+strlen(one); ptr++){
        *concat_ptr = *ptr;
        concat_ptr++;
    }
    for(char *ptr = two; ptr < two+strlen(two); ptr++){
        *concat_ptr = *ptr;
        concat_ptr++;
    }

    printf("Result of concatenation: %s\n", concat);

    free(concat);

    return 0;
}