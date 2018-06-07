/*
JTSK-320112
a3 p4.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

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