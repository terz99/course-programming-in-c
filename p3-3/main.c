/*
JTSK-320112
a3 p3.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct linked_list{
    char info;
    struct linked_list *next;
};

struct linked_list* push(struct linked_list *myll, char val){

    /* This function adds an element at the beginning of the list */

    struct linked_list *newll;
    newll = (struct linked_list*)malloc(sizeof(struct linked_list));
    if(newll == NULL){
        /* Bad allocation */
        return myll;
    }
    newll->info = val;
    newll->next = myll;
    return newll;
}

struct linked_list* erase(struct linked_list *myll, char val){

    /* This function erases all the occurances of val in the list */

    if(myll->info == val){

        if(myll->next == NULL){
            free(myll);
            return myll;
        } else {
            while(myll->info == val){
                myll->info = myll->next->info;
                struct linked_list *next = myll->next;
                myll->next = myll->next->next;
                free(next);
            }
        }
    }


    /* Flag is used to indicate whether there was a deletion */
    int flag = 0;
    struct linked_list *cursor = myll;
    while(cursor->next != NULL){
        if(cursor->next->info == val){
            struct linked_list *tmp = cursor->next;
            cursor->next = cursor->next->next;
            free(tmp);
            flag = 1;
        } else {
            cursor = cursor->next;
        }
    }

    if(!flag){
        printf("The element is not in the list!\n");
    }

    return myll;
}

void print(struct linked_list *myll){

    /* This function prints the list */
    struct linked_list *cursor;
    for(cursor = myll; cursor; cursor = cursor->next){
        printf("%c ", cursor->info);
    }
    printf("\n");
}

void print_backwards(struct linked_list *myll){

    /* This function prints the list backwards */
    if(myll == NULL){
        return;
    }

    print_backwards(myll->next);
    printf("%c ", myll->info);
}

struct linked_list* dispose_linked_list(struct linked_list *myll){
    
    /* This function frees the memory */
    
    struct linked_list *next;
    while(myll != NULL){
        next = myll->next;
        free(myll);
        myll = next;
    }
    return myll;
}

int main(){

    struct linked_list *myll = NULL;
    /* The flag is used to indicate the activity of the infinite loop */
    int flag = 1;
    while(flag){

        int option;
        scanf("%d", &option);
        getchar();

        char val;
        switch(option){

            case 1:
                scanf("%c", &val);
                getchar();
                myll = push(myll, val);
            break;
            case 2:
                scanf("%c", &val);
                getchar();
                myll = erase(myll, val);
            break;
            case 3:
                print(myll);
            break;
            case 4:
                print_backwards(myll);
                printf("\n");
            break;
            case 5:
                myll = dispose_linked_list(myll);
                flag = 0;
            break;
            default:
                printf("Unknown operation\n");
        }
    }

    return 0;
}