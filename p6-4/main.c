/*
JTSK-320112
a6 p4.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct username{
    char *name;
    int pos;
} Username;

int main(){

    char filename[255];
    fgets(filename, 255, stdin);
    filename[strlen(filename)-1] = '\0';

    FILE *fileptr;
    fileptr = fopen(filename, "r");
    if(fileptr == NULL){
        fprintf(stderr, "Cannot open file!\n");
        exit(1); // file does not exits!
    }

    // read usernames
    Username usernames[255];
    char line[255];
    int usernames_size = 0;
    usernames[0].pos = 0;
    while(1){

        fscanf(fileptr, "%s\n", line);

        usernames[usernames_size].name = (char*)malloc(strlen(line)*sizeof(char));
        strcpy(usernames[usernames_size].name, line);
        usernames[usernames_size].pos += strlen(line) + 1;

        fscanf(fileptr, "%s\n", line);
        usernames[usernames_size+1].pos = usernames[usernames_size].pos + strlen(line) + 1;

        usernames_size++;

        if(feof(fileptr)){
            break;
        }
    }

    int flag = 1; // this flag indicates activity of the loop
    while(flag){

        char username[255];
        fgets(username, 255, stdin);
        username[strlen(username)-1] = '\0';

        if(strcmp(username, "exit") == 0){
            flag = 0;
        } else {

            char pass[255];
            fgets(pass, 255, stdin);
            pass[strlen(pass)-1] = '\0';

            int offset = 0;
            for(int i = 0; i < usernames_size; i++){
                if(strcmp(usernames[i].name, username) == 0){
                    offset = usernames[i].pos;
                    break;
                }
            }

            fseek(fileptr, offset, SEEK_SET);
            char check_pass[255];
            fscanf(fileptr, "%s\n", check_pass);
            if(strcmp(check_pass, pass) == 0){
                printf("Access to user %s is granted.\n", username);
            } else {
                printf("Access to user %s is denied.\n", username);
            }
        }
    }

    printf("Exiting ...\n");
    for(int i = 0; i < usernames_size; i++){
        free(usernames[i].name);
    }
    fclose(fileptr);

    return 0;
}