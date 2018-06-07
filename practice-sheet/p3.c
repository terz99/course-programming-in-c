#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(int **A, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main(){

    FILE *file = fopen("matrix.dat", "r");
    if(file == NULL){
        // Cannot open the file
        exit(1);
    }

    int rows, cols;
    fscanf(file, "%d\n", &rows);
    fscanf(file, "%d\n", &cols);
    int **mat; 
    mat = (int**)malloc(rows*sizeof(int*));
    for(int i = 0; i < rows; i++){
        mat[i] = (int*)malloc(cols*sizeof(int));
    }
    if(mat == NULL){
        // Bad alloc
        exit(1);
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            mat[i][j] = 0;
        }
    }
    int x, y, val;
    while(fscanf(file, "%d %d %d\n", &x, &y, &val) != EOF){
        mat[x-1][y-1] = val;
    }

    fclose(file);

    print_matrix(mat, rows, cols);

    return 0;
}