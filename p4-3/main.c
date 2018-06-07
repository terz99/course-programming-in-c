/*
JTSK-320112
a4 p3.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void print(int *arr, int sz){

    /* The function prints the array 'arr' of size 'sz' */

    for(int i = 0; i < sz; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int asc(const void *va, const void *vb){

    /* Compare function to sort in ascending order */

    const int *a = (const int*)va;
    const int *b = (const int*)vb;
    if(*a < *b) return -1;
    if(*a > *b) return 1;
    return 0;
}

int desc(const void *va, const void *vb){

    /* Compare function to sort in descending order */

    const int *a = (const int*)va;
    const int *b = (const int*)vb;
    if(*a > *b) return -1;
    if(*a < *b) return 1;
    return 0;
}

int main(){

    int n;
    scanf("%d", &n);
    getchar();
    int *arr;
    arr = (int*)malloc(n*sizeof(int));
    if(arr == NULL){
        /* Bad alloc */
        exit(1);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        getchar();
    }

    while(1){

        char op;
        scanf("%c", &op);
        getchar();

        if(op == 'a'){
            qsort(arr, n, sizeof(int), asc);
            print(arr, n);
        } else if(op == 'd'){
            qsort(arr, n, sizeof(int), desc);
            print(arr, n);
        } else if(op == 'e'){
            break;
        } else {
            printf("Unknown command. Try again!\n");
        }
    }

    free(arr);

    return 0;
}