/*
JTSK-320112
a2 p1.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int n;
    scanf("%d", &n);
    getchar();

    float *arr = (float*)malloc(n*sizeof(float));
    if(arr == NULL){
        // bad allocation
        exit(1);
    }

    for(float *ptr = arr; ptr < arr+n; ptr++){
        scanf("%f", ptr);
        getchar();
    }

    for(float *ptr = arr; ptr < arr+n; ptr++){
        if(*ptr < 0){
            printf("Before the first negative value: %ld elements\n", ptr-arr);
            break;
        }
    }

    free(arr);

    return 0;
}