/*
JTSK-320112
a3 p2.c
Dushan Terzikj
d.terzikj@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>

struct linked_list{
    int val;
    struct linked_list *next;
};
int list_size = 0;

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
    list_size++;
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
    list_size++;
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
    list_size--;
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
    list_size = 0;
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

struct linked_list* insert(struct linked_list *myll, int pos, int val){

    /* This function inserts an element on position pos
    if the position is out of bounds then it prints 'Invalid position!' */

    if(pos < 0 || pos > list_size){
        printf("Invalid position!\n");
        return myll;
    }

    if(pos == 0){
        struct linked_list *newll;
        newll = (struct linked_list*)malloc(sizeof(struct linked_list));
        if(newll == NULL){
            return myll;
        }
        newll->val = val;
        newll->next = myll;
        list_size++;
        return newll;
    } else {

        struct linked_list *cursor = myll, *newll, *next;
        while(pos > 1){
            pos--;
            cursor = cursor->next;
        }
        newll = (struct linked_list*)malloc(sizeof(struct linked_list));
        if(newll == NULL){
            return myll;
        }
        next = cursor->next;
        newll->val = val;
        newll->next = next;
        cursor->next = newll;
        list_size++;
        return myll;
    }
}

struct linked_list* reverse(struct linked_list *myll){

    /* This function reverses the linked list */

    if(myll == NULL){
        return myll;
    }

    struct linked_list *curr, *next, *prev;
    prev = NULL;
    curr = myll;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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

        int val, pos;
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
            case 'i':
                scanf("%d%d", &pos, &val);
                getchar();
                myll = insert(myll, pos, val);
            break;
            case 'R':
                myll = reverse(myll);
            break;
            default:
                /* Handling the invalid outputs */
                printf("Unknown command. Try again\n");
        }
    }

    return 0;
}