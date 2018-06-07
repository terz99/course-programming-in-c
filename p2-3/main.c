/*
JTSK-320112
a2 p3.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

void multiply(int **A, int **B, int **C, int n, int m, int p){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            C[i][j] = 0;
            for(int k = 0; k < m; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main(){

    int **A, **B, **C;
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    getchar();

    // allocation of matrices
    A = (int**)malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        A[i] = (int*)malloc(sizeof(int)*m);
    }
    B = (int**)malloc(sizeof(int*)*m);
    for(int i = 0; i < m; i++){
        B[i] = (int*)malloc(sizeof(int)*p);
    }
    C = (int**)malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        C[i] = (int*)malloc(sizeof(int)*p);
    }

    // check if allocation is good
    if(A == NULL || B == NULL || C == NULL){
        exit(1);
    }

    // input A and B
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &A[i][j]);
            getchar();
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            scanf("%d", &B[i][j]);
            getchar();
        }
    }

    multiply(A, B, C, n, m, p);

    // output

    printf("Matrix A:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B:\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < p; j++){
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("The multiplication result AxB:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // deallocation
    for(int i = 0; i < n; i++){
        free(A[i]);
        free(C[i]);
    }
    for(int i = 0; i < m; i++){
        free(B[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}