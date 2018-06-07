/*
JTSK-320112
a6 p5.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *file;
    file = fopen("chars.txt", "rb");

    if(file == NULL){
        fprintf(stderr, "Cannot open file!\n");
        exit(1); // file cannot be opened
    }

    // getting size of the file
    fseek(file, 0, SEEK_END);
    long int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // read from file
    char *buffer = (char*)malloc((file_size+1)*sizeof(char));
    if(buffer == NULL){
        fprintf(stderr, "Cannot allocate memory!\n");
        exit(1); // memory allocation problem
    }
    fread(buffer, sizeof(char), file_size, file);
    fclose(file);

    // write sum into 'codesum.txt'
    int sum = (int)buffer[0] + (int)buffer[2];
    file = fopen("codesum.txt", "wb");
    if(file == NULL){
        fprintf(stderr, "Cannot open file!\n");
        exit(1); // cannot open file
    }
    fwrite(&sum, sizeof(int), 1, file);
    fclose(file);



    return 0;
}