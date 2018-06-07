/*
JTSK-320112
a3 p1.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct linked_list{
    int val;
    struct linked_list *next;
};

struct linked_list* push_back(struct linked_list *myll, int val){

    /*
    This method pushesh a new element at the end of the list
    and returns the newly formed list with the new element
    */

    struct linked_list *newll, *cursor;
    newll = (struct linked_list*)malloc(sizeof(struct linked_list));
    if(newll == NULL){
        return myll;
    }
    newll->val = val;
    newll->next = NULL;
    if(myll == NULL){
        return newll;
    }
    cursor = myll;
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    cursor->next = newll;
    return myll; 
}

struct linked_list* push_front(struct linked_list *myll, int val){
    
    /*
    This method pushesh a new element at the beginning of the list
    and returns the newly formed list with the new element
    */

    struct linked_list *newll;
    newll = (struct linked_list*)malloc(sizeof(struct linked_list));
    if(newll == NULL){
        return myll;
    }
    newll->val = val;
    newll->next = myll;
    return newll; 
}

struct linked_list* pop_front(struct linked_list *myll){

    /*
    This method removes the first element of the list
    */

    if(myll == NULL){
        return myll;
    }
    struct linked_list *newll = myll->next;
    free(myll);
    return newll;
}

struct linked_list* dispose_linked_list(struct linked_list *myll){
    
    /*
    This method deletes the whole linked list and frees
    the dinamically allocated memory
    */

    struct linked_list *nextll = NULL;
    while(myll != NULL){
        nextll = myll->next;
        free(myll);
        myll = nextll;
    }
    return myll;
}

void print_linked_list(struct linked_list *myll){

    /*
    This method prints the linked list in one line
    */

    struct linked_list *ptr;
    for(ptr = myll; ptr; ptr = ptr->next){
        printf("%d ", ptr->val);
    }
    printf("\n");
}

int main(){

    struct linked_list *myll = NULL;
    /* The flag is used to indicate the activity of 
    the infinite while loop */
    int flag = 1;
    while(flag){

        char ch;
        scanf("%c", &ch);
        getchar();

        int val;
        switch(ch){
            case 'a':
                scanf("%d", &val);
                getchar();
                myll = push_back(myll, val);
                break;
            case 'b':
                scanf("%d", &val);
                getchar();
                myll = push_front(myll, val);
            break;
            case 'r':
                myll = pop_front(myll);
            break;
            case 'p':
                print_linked_list(myll);
            break;
            case 'q':
                myll = dispose_linked_list(myll);
                /* Deactivate the flag and stop the program */
                flag = 0;
            break;
            default:
                /* Handling the invalid outputs */
                printf("Unknown command. Try again\n");
        }
    }

    return 0;
}