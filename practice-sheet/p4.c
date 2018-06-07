#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
    char str[20];
    struct list* next;
};

struct list* insertBegin(struct list* mylist, char str[]){
    if(mylist == NULL){
        mylist = (struct list*)malloc(sizeof(struct list));
        strcpy(mylist->str, str);
        mylist->next = NULL;
        return mylist;
    }

    struct list* curr = (struct list*)malloc(sizeof(struct list));
    strcpy(curr->str, str);
    curr->next = mylist;
    return curr;
}

void printList(struct list* mylist){
    struct list* curr = mylist;
    while(curr != NULL){
        printf("%s ", curr->str);
        curr = curr->next;
    }
    printf("\n");
}

int main(){

    struct list* mylist;
    mylist = NULL;
    while(1){

        char str[20];
        fgets(str, 20, stdin);
        str[strlen(str)-1] = '\0';
        if(strcmp(str, "ZZZ") == 0){
            break;
        } else {
            mylist = insertBegin(mylist, str);
            printList(mylist);
        }
    }

    return 0;
}