#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct river{
    char name[40];
    int length;
    int drainage_area;
};

int cmp(const void* a, const void* b){
    const struct river* va = (const struct river*)a;
    const struct river* vb = (const struct river*)b;
    return va->length - vb->length;
}

int main(){

    FILE *file = fopen("data.txt", "r");
    if(file == NULL){
        // Cannot open file
        exit(1);
    }
    struct river rivers[30];
    char name[40];
    int length;
    int drainage_area;
    int i;
    for(i = 0; fscanf(file, "%s %d %d\n", name, &length, &drainage_area) != EOF; i++){
        rivers[i].drainage_area = drainage_area;
        rivers[i].length = length;
        strcpy(rivers[i].name, name);
    }
    fclose(file);

    qsort(rivers, i, sizeof(rivers[0]), cmp);

    char filename[40];
    fgets(filename, 40, stdin);
    filename[strlen(filename)-1] = '\0';
    file = fopen(filename, "w");
    if(file == NULL){
    	// Bad allocation
	exit(1);
    }

    for(int j = 0; j < i; j++){
    	fprintf(file, "%s %d %d\n", rivers[j].name, rivers[j].length, rivers[j].drainage_area);
    }
    fclose(file);

    return 0;
}
