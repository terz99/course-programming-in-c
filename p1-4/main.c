/*
JTSK-320112
a1 p4.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

#define INTERMEDIATE

int get_scalar_product(int* comp, int* v, int* u, int n){

    /*
    This function returns the scalar product of v and u with size n
    Also it calculates the intermediate values of v and u 
    and stores them in comp
    */

    int ret = 0;
    for(int i = 0; i < n; i++){
        comp[i] = v[i]*u[i];
        ret = ret + v[i]*u[i];
    }
    return ret;
}

int main(){

    int n;
    scanf("%d", &n);
    getchar();

    // dynamically allocate the two vectors
    int *v = (int*)malloc(n*sizeof(int));
    int *u = (int*)malloc(n*sizeof(int));
    int *comp = (int*)malloc(n*sizeof(int));
    if(v == NULL || u == NULL || comp == NULL){
        // check if dynamic allocation went wrong
        printf("malloc failed\n");
        exit(1);
    }

    // input the two vectors
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        getchar();
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &u[i]);
        getchar();
    }

    int scalar_product = get_scalar_product(comp, v, u, n);
    #ifdef INTERMEDIATE
    printf("The intermediate product values are:\n");
    for(int i = 0; i < n; i++){
        printf("%d\n", comp[i]);
    }
    #endif

    printf("The scalar product is: %d\n", scalar_product);

    free(comp);
    free(v);
    free(u);

    return 0;
}