/*
JTSK-320112
a6 p5.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   
    // read n
    int n;
    scanf("%d", &n);
    getchar();

    // read the names of the files
    char *filenames[n];
    for(int i = 0; i < n; i++){
        filenames[i] = (char*)malloc(255*sizeof(char));
        fgets(filenames[i], 255, stdin);
        filenames[i][strlen(filenames[i])-1] = '\0';
    }

    // open a file to write the output, called 'output.txt'
    FILE *f_write;
    f_write = fopen("output.txt", "wb");

    if(f_write == NULL){
        // if file opening failed, exit the program
        fprintf(stderr, "Cannot open file!\n");
        exit(1);
    }

    printf("Concating the content of %d files ...\nThe result is:\n", n);

    for(int i = 0; i < n; i++){

        FILE *fptr;
        fptr = fopen(filenames[i], "rb");
        if(fptr == NULL){
            fprintf(stderr, "Cannot open file!\n");
            exit(1); // file does not exits!
        }

        // read from current file and append the data from the files to the output file
        char *buffer;

        // next 3 lines of code is getting the size of the file
        fseek(fptr, 0, SEEK_END);
        int file_size = ftell(fptr);
        fseek(fptr, 0, SEEK_SET);
        buffer = (char*)malloc(sizeof(char)*(file_size+1));

        fread(buffer, sizeof(char), file_size, fptr);
        fwrite(buffer, sizeof(char), file_size, f_write);
        printf("%s\n", buffer);

        fclose(fptr);

        // set new line after reading all the data from one file
        strcpy(buffer, "\n");
        fwrite(buffer, sizeof(char), strlen(buffer), f_write);
        free(buffer);
    }

    // memory deallocation
    for(int i = 0; i < n; i++){
        free(filenames[i]);
    }
    fclose(f_write);
    printf("The result was written into output.txt\n");

   return 0;
}