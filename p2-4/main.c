/*
JTSK-320112
a2 p4.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_elements(int ***arr, int rows, int columns, int depth){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            for(int k = 0; k < depth; k++){
                scanf("%d", &arr[i][j][k]);
                getchar();
            }
        }
    }
}

void print_elements(int ***arr, int rows, int columns, int depth){
    for(int k = 0; k < depth; k++){
        printf("Section %d:\n", k+1);
        for(int j = 0; j < columns; j++){
            for(int i = 0; i < rows; i++){
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
    }
}

int main(){

    int rows, columns, depth;
    scanf("%d%d%d", &rows, &columns, &depth);
    getchar();

    int ***arr;

    // allocation
    arr = (int***)malloc(sizeof(int**)*rows);
    for(int i = 0; i < rows; i++){
        arr[i] = (int**)malloc(sizeof(int*)*columns);
        for(int j = 0; j < columns; j++){
            arr[i][j] = (int*)malloc(sizeof(int)*depth);
        }
    }

    if(arr == NULL){
        // bad alloc
        exit(1);
    }

    read_elements(arr, rows, columns, depth);
    print_elements(arr, rows, columns, depth);

    // deallocation
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
    

    return 0;
}